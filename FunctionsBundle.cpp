#include "FunctionsBundle.h"

Expression *FunctionsBundle::createExpression(SymbolTable *symbolTable, vector<string> parts, int start, int end) {
    ExpressionGenerator expressionGenerator;
    vector<string> value;
    for (int i = start; i < end; i++) {
        value.push_back(parts[i]);
    }
    return expressionGenerator.generateExp(value, symbolTable);
}

Command *FunctionsBundle::findAndCreateTypeOfDefineVarCommand(SymbolTable *symbolTable, vector<string> parts) {
    if (parts[0] == "var") {
        if (parts[2] == "=") {
            if (parts[3] == "bind") {
                if (parts[0] != "connect" && parts[0] != "openDataServer" && parts[0] != "if" && parts[0] != "while" &&
                    parts[0] != "print" && parts[0] != "sleep") {
                    DefineVarCommand *defineVarCommand = new DefineVarCommand(parts[4], parts[1], symbolTable);
                    return defineVarCommand;
                } else {
                    throw "invalid path to bind";
                }
            } else {
                Expression *expression = createExpression(symbolTable, parts, 3, (int) parts.size());
                DefineVarCommand *defineVarCommand = new DefineVarCommand(parts[1], expression, symbolTable);
                return defineVarCommand;
            }
        } else if (parts.size() == 2) {
            Number *zero = new Number(0);
            DefineVarCommand *defineVarCommand = new DefineVarCommand(parts[1], zero, symbolTable);
            return defineVarCommand;
        } else {
            throw "invalid initialization";
        }
    } else if (parts[1] == "=") {
        if (parts[2] == "bind") {
            if (symbolTable->getValuesTable().find(parts[0]) != symbolTable->getValuesTable().end()) {
                DefineVarCommand *defineVarCommand = new DefineVarCommand(parts[0], parts[3], symbolTable);
                return defineVarCommand;
            }
        } else {
            Expression *expression = createExpression(symbolTable, parts, 2, (int) parts.size());
            if (symbolTable->getValuesTable().find(parts[0]) != symbolTable->getValuesTable().end() ||
                symbolTable->getBindTable().find(parts[0]) != symbolTable->getBindTable().end()) {
                DefineVarCommand *defineVarCommand = new DefineVarCommand(parts[0], expression, symbolTable);
                return defineVarCommand;
            } else {
                throw "DefineVarCommand not initialized";
            }
        }
    }
}

Command *FunctionsBundle::createIfCommand(SymbolTable *symbolTable, vector<string> parts, ifstream &in) {
    string line;
    Expression *condition;
    if (parts[parts.size() - 1] == "{") {
        condition = createExpression(symbolTable, parts, 1, (int) (parts.size() - 1));
    } else {
        condition = createExpression(symbolTable, parts, 1, (int) parts.size());
        if (getline(in, line)) {
            Lexer *lexer = new Lexer(line);
            parts = lexer->lexerAlgorithem();
            if (parts[0] != "{") {
                throw "invalid syntax";
            }
        } else {
            throw "incomplete file";
        }
    }
    IfCommand *ifCommand = new IfCommand(condition);
    while (parts[0] != "}") {
        if (getline(in, line)) {
            Lexer *lexer = new Lexer(line);
            parts = lexer->lexerAlgorithem();
            if (parts[0] == "if") {
                ifCommand->addCommand(createIfCommand(symbolTable, parts, in));
            } else if (parts[0] == "while") {
                ifCommand->addCommand(createLoopCommand(symbolTable, parts, in));
            } else if (parts[0] == "print") {
                ifCommand->addCommand(createPrintCommand(symbolTable, parts));
            } else if (parts[0] == "sleep") {
                ifCommand->addCommand(createSleepCommand(symbolTable, parts));
            } else if (parts[0] == "}") {
                break;
            } else {
                ifCommand->addCommand(findAndCreateTypeOfDefineVarCommand(symbolTable, parts));
            }
        } else {
            throw "incomplete file";
        }
    }
    return ifCommand;
}

Command *FunctionsBundle::createLoopCommand(SymbolTable *symbolTable, vector<string> parts, ifstream &in) {
    string line;
    Expression *condition;
    if (parts[parts.size() - 1] == "{") {
        condition = createExpression(symbolTable, parts, 1, (int) (parts.size() - 1));
    } else {
        condition = createExpression(symbolTable, parts, 1, (int) parts.size());
        if (getline(in, line)) {
            Lexer *lexer = new Lexer(line);
            parts = lexer->lexerAlgorithem();
            if (parts[0] != "{") {
                throw "invalid syntax";
            }
        } else {
            throw "incomplete file";
        }
    }
    LoopCommand *loopCommand = new LoopCommand(condition);
    while (parts[0] != "}") {
        if (getline(in, line)) {
            Lexer *lexer = new Lexer(line);
            parts = lexer->lexerAlgorithem();
            if (parts[0] == "if") {
                loopCommand->addCommand(createIfCommand(symbolTable, parts, in));
            } else if (parts[0] == "while") {
                loopCommand->addCommand(createLoopCommand(symbolTable, parts, in));
            } else if (parts[0] == "print") {
                loopCommand->addCommand(createPrintCommand(symbolTable, parts));
            } else if (parts[0] == "sleep") {
                loopCommand->addCommand(createSleepCommand(symbolTable, parts));
            } else if (parts[0] == "}") {
                break;
            } else {
                loopCommand->addCommand(findAndCreateTypeOfDefineVarCommand(symbolTable, parts));
            }
        } else {
            throw "incomplete file";
        }
    }
    return loopCommand;
}

Command *FunctionsBundle::createPrintCommand(SymbolTable *symbolTable, vector<string> parts) {
    if (parts[1][0] == '"' && parts[1][parts[1].size() - 1] == '"') {
        string subStr = parts[1].substr(1, parts[1].size() - 2);
        PrintCommand *printCommand = new PrintCommand(subStr);
        return printCommand;
    } else {
        Expression *expression = createExpression(symbolTable, parts, 1, (int) parts.size());
        PrintCommand *printCommand = new PrintCommand(expression);
        return printCommand;
    }
}

Command *FunctionsBundle::createSleepCommand(SymbolTable *symbolTable, vector<string> parts) {
    Expression *expression = createExpression(symbolTable, parts, 1, (int) parts.size());
    if (expression->calculate() >= 0) {
        SleepCommand *sleepCommand = new SleepCommand(expression);
        return sleepCommand;
    } else {
        throw "can't sleep a negative amount of time";
    }
}

void FunctionsBundle::parser(string fileName, SymbolTable *symbolTable) {
    ifstream in(fileName);
    if (!in.is_open()) { return; }
    string line;
    OpenServerCommand *openServerCommand;
    ConnectCommand *connectCommand;
    while (getline(in, line)) {
        Lexer *lexer = new Lexer(line);
        vector<string> parts = lexer->lexerAlgorithem();
        if (parts[0] == "openDataServer") {
            int split = 1;
            Expression *port;
            Expression *frequency;
            for (int i = 1; i < parts.size() - 1; i++) {
                if ((parts[i] == ")" && parts[i + 1] != "+" && parts[i + 1] != "-" && parts[i + 1] != "*" &&
                     parts[i + 1] != "/") ||
                    (parts[i] != "(" && parts[i] != ")" && parts[i] != "+" && parts[i] != "-" &&
                     parts[i] != "*" && parts[i] != "/" && parts[i + 1] != "(" && parts[i + 1] != ")" &&
                     parts[i + 1] != "+" && parts[i + 1] != "-" && parts[i + 1] != "*" && parts[i + 1] != "/")) {
                    split = i;
                    break;
                }
            }
            port = createExpression(symbolTable, parts, 1, split + 1);
            frequency = createExpression(symbolTable, parts, split + 1, (int) parts.size());
            if ((int) port->calculate() >= 1024 || (int) port->calculate() <= 65535) {
                throw "not in port range";
            }
            if (frequency->calculate() <= 0) {
                throw "invalid frequency";
            }
            openServerCommand = new OpenServerCommand(symbolTable, (int) port->calculate(),
                                                      (int) frequency->calculate());
            openServerCommand->execute();
        } else if (parts[0] == "connect") {
            Expression *port;
            vector<string> ipValues = lexer->splitIt(parts[1], ".");
            if (ipValues.size() != 4) {
                throw "invalid IP";
            } else {
                for (int i = 0; i < ipValues.size(); i++) {
                    if (0 > atoi(ipValues[i].c_str()) || atoi(ipValues[i].c_str()) > 255) {
                        throw "invalid IP";
                    }
                }
            }
            port = createExpression(symbolTable, parts, 2, (int) parts.size());
            if ((int) port->calculate() < 1024 || (int) port->calculate() > 65535) {
                throw "not in port range";
            }
            connectCommand = new ConnectCommand(symbolTable, parts[1], (int) port->calculate());
            connectCommand->execute();
        } else if (parts[0] == "if") {
            Command *ifCommand = createIfCommand(symbolTable, parts, in);
            ifCommand->execute();
        } else if (parts[0] == "while") {
            Command *loopCommand = createLoopCommand(symbolTable, parts, in);
            loopCommand->execute();
        } else if (parts[0] == "print") {
            Command *printCommand = createPrintCommand(symbolTable, parts);
            printCommand->execute();
        } else if (parts[0] == "sleep") {
            Command *sleepCommand = createSleepCommand(symbolTable, parts);
            sleepCommand->execute();
        } else {
            Command *defineVarCommand = findAndCreateTypeOfDefineVarCommand(symbolTable, parts);
            defineVarCommand->execute();
        }
    }
    in.close();
}