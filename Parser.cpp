#include "Parser.h"
#include "CommandenterC.h"

#define command 0
// constructor that takes the vector string and makes on iterator
Parser::Parser(vector<string> &text) : toInterpret(text) {
    this->it = this->toInterpret.begin();
    this->creator = new ExpressionFactory(expressionMap,commandMap,it,toInterpret);
}


void Parser::split() {
    while (it != this->toInterpret.end()) {
        Expression *expression;
        // if symbol instead of command var, assign the define command.
        if (symbolExists(*it))
            expression = this->expressionMap.find("var")->second;
        else
            expression = this->creator->create(*it);;
        //call the expression command.
        if (expression != nullptr) {
            expression->calculate();
        }
    }
}
// if it's exists.
bool Parser::symbolExists(string var) {
    for (auto iter = SymbolTable::instance()->getBegin(); iter != SymbolTable::instance()->getEnd(); iter++) {
        if (SymbolTable::instance()->atTable(var)) {
            return true;
        }
    }
    return false;
}
// distructor , realse all the alloacted memory of the command and the expresion map
Parser::~Parser() {
    for (auto itemp = this->expressionMap.begin();
         itemp != this->expressionMap.end(); itemp++) {
        map<string,Command*>::iterator t = this->commandMap.find(itemp->first);
        delete t->second;
        delete itemp->second;
    }
    delete creator;
}
