//
// Created by issa on 9/9/19.
//

#ifndef PROJECT_EXPRESSIONFACTORY_H
#define PROJECT_EXPRESSIONFACTORY_H

#include <map>
#include <vector>
#include "Expression.h"
#include "Command.h"

class ExpressionFactory {
private:
    map<string, Expression*> expressionMap;
    map<string, Command*> commandMap;
    vector<string> toInterpret;
    vector<string>::iterator it;
public:
    ExpressionFactory(map<string,Expression*> &expressionMap, map<string,Command*> &commandMap,vector<string>::iterator &it
    ,vector<string> toInt);
    Expression* create(string exp);
};


#endif //PROJECT_EXPRESSIONFACTORY_H
