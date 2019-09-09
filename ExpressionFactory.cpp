//
// Created by issa on 9/9/19.
//

#include "ExpressionFactory.h"
#include "CommandExpression.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "whileCommand.h"
#include "CommandenterC.h"

Expression *ExpressionFactory::create(string exp) {
    if(exp == "openDataServer"){
        this->commandMap["openDataServer"] = new OpenServerCommand(it);
        this->expressionMap["openDataServer"] = new CommandExpression(toInterpret, this->commandMap["openDataServer"]);
        return this->expressionMap.find(exp)->second;
    }
    if(exp == "connect"){
        this->commandMap["connect"] = new ConnectCommand(it);
        this->expressionMap["connect"] = new CommandExpression(toInterpret, this->commandMap["connect"]);
        return this->expressionMap.find(exp)->second;
    }
    if(exp == "var"){
        this->commandMap["var"] = new DefineVarCommand(it);
        this->expressionMap["var"] = new CommandExpression(toInterpret, this->commandMap["var"]);
        return this->expressionMap.find(exp)->second;
    }
    if(exp == "while") {
        this->commandMap["while"] = new whileCommand(it);
        this->expressionMap["while"] = new CommandExpression(toInterpret, this->commandMap["while"]);
        return this->expressionMap.find(exp)->second;
    }
    if(exp == "if") {
        this->commandMap["if"] = new ifCommand(it);
        this->expressionMap["if"] = new CommandExpression(toInterpret, this->commandMap["if"]);
        return this->expressionMap.find(exp)->second;
    }
    if(exp == "print") {
        this->commandMap["print"] = new printCommand(it);
        this->expressionMap["print"] = new CommandExpression(toInterpret, this->commandMap["print"]);
        return this->expressionMap.find(exp)->second;
    }
    if(exp == "EnterC") {
        this->commandMap["EnterC"] = new CommandenterC(it);
        this->expressionMap["EnterC"] = new CommandExpression(toInterpret, this->commandMap["EnterC"]);
        return this->expressionMap.find(exp)->second;
    }
    if(exp == "sleep") {
        this->commandMap["sleep"] = new Sleep(it);
        this->expressionMap["sleep"] = new CommandExpression(toInterpret, this->commandMap["sleep"]);
        return this->expressionMap.find(exp)->second;
    }
}

ExpressionFactory::ExpressionFactory(map<string, Expression *> &expressionMap, map<string, Command *> &commandMap,
                                     vector<string>::iterator &it, vector<string> toInt) {
}







