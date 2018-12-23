#include "FunctionsBundle.h"

Expression* FunctionBundles::createExpression(map<string,Command*> commandTable, vector<string> parts, int start, int
end) {
    ExpressionGenerator expressionGenerator;
    vector<string> value;
    for ( int i = start; i < end; i++) {
        value.push_back(parts[i]);
    }
    return expressionGenerator.generateExp(value, commandTable);
}

string FunctionBundles::findAndCreateTypeOfDefineVarCommand(SymbolTable* symbolTable, vector<string> parts) {
    if (parts[0] == "var" && parts[2] == "=") {
        if (parts[3] == "bind") {

        } else {
            Expression* expression = createExpression(symbolTable->getCommandTable(), parts, 3, (int) parts.size());
            DefineVarCommand* defineVarCommand = new DefineVarCommand(parts[1], expression->calculate(), symbolTable);
            defineVarCommand->execute();
            return parts[1];
        }
    } else if (parts[1] == "=") {
        if (parts[2] == "bind") {

        } else {
            Expression* expression = createExpression(symbolTable->getCommandTable(), parts, 2, (int) parts.size());
            if (symbolTable->getCommandTable().find(parts[0]) != symbolTable->getCommandTable().end()) {
                ((DefineVarCommand*)symbolTable->getCommandTable().at(parts[0]))->setValue(expression->calculate());
                return parts[0];
            } else {
                throw "DefineVarCommand not initialized";
            }
        }
    }
}

Command* FunctionBundles::createIfCommand(SymbolTable* symbolTable, vector<string> parts, stack<Command*> commands,
        ifstream& in) {
    string line;
    Expression* condition;
    if (parts[parts.size() - 1] == "{") {
        condition = createExpression(symbolTable->getCommandTable(), parts, 1, (int) (parts.size() - 1));
    } else {
        condition = createExpression(symbolTable->getCommandTable(), parts, 1, (int) parts.size());
        if (getline(in, line)) {
            Lexer* lexer = new Lexer(line);
            parts = lexer->lexerAlgorithem();
            if (parts[0] != "{") {
                throw "invalid syntax";
            }
        } else {
            throw "incomplete file";
        }
    }
    IfCommand* ifCommand = new IfCommand(condition);
    commands.push((Command*)ifCommand);
    while (parts[0] != "}") {
        if (getline(in, line)) {
            Lexer* lexer = new Lexer(line);
            parts = lexer->lexerAlgorithem();
            if (parts[0] == "if") {
                if (typeid(commands.top()).name() == "IfCommand") {
                    ((IfCommand*)commands.top())->addCommand(createIfCommand(symbolTable, parts, commands, in));
                    commands.pop();
                } else if (typeid(commands.top()).name() == "LoopCommand") {
                    ((LoopCommand*)commands.top())->addCommand(createIfCommand(symbolTable, parts, commands, in));
                    commands.pop();
                }
            } else if (parts[0] == "while") {
                if (typeid(commands.top()).name() == "IfCommand") {
                    ((IfCommand*)commands.top())->addCommand(createLoopCommand(symbolTable, parts, commands, in));
                    commands.pop();
                } else if (typeid(commands.top()).name() == "LoopCommand") {
                    ((LoopCommand*)commands.top())->addCommand(createLoopCommand(symbolTable, parts, commands, in));
                    commands.pop();
                }
            } else {
                string str = findAndCreateTypeOfDefineVarCommand(symbolTable, parts);
                if (typeid(commands.top()).name() == "IfCommand") {
                    ((IfCommand*)commands.top())->addCommand(symbolTable->getCommandTable().at(str));
                } else if (typeid(commands.top()).name() == "LoopCommand") {
                    ((LoopCommand*)commands.top())->addCommand(symbolTable->getCommandTable().at(str));
                }
            }
        } else {
            throw "incomplete file";
        }
    }
    return commands.top();
}

Command* FunctionBundles::createLoopCommand(SymbolTable* symbolTable, vector<string> parts, stack<Command*> commands,
        ifstream& in) {
    string line;
    Expression* condition;
    if (parts[parts.size() - 1] == "{") {
        condition = createExpression(symbolTable->getCommandTable(), parts, 1, (int) (parts.size() - 1));
    } else {
        condition = createExpression(symbolTable->getCommandTable(), parts, 1, (int) parts.size());
        if (getline(in, line)) {
            Lexer* lexer = new Lexer(line);
            parts = lexer->lexerAlgorithem();
            if (parts[0] != "{") {
                throw "invalid syntax";
            }
        } else {
            throw "incomplete file";
        }
    }
    LoopCommand* loopCommand = new LoopCommand(condition);
    commands.push((Command*)loopCommand);
    while (parts[0] != "}") {
        if (getline(in, line)) {
            Lexer* lexer = new Lexer(line);
            parts = lexer->lexerAlgorithem();
            if (parts[0] == "if") {
                if (typeid(commands.top()).name() == "IfCommand") {
                    ((IfCommand*)commands.top())->addCommand(createIfCommand(symbolTable, parts, commands, in));
                    commands.pop();
                } else if (typeid(commands.top()).name() == "LoopCommand") {
                    ((LoopCommand*)commands.top())->addCommand(createIfCommand(symbolTable, parts, commands, in));
                    commands.pop();
                }
            } else if (parts[0] == "while") {
                if (typeid(commands.top()).name() == "IfCommand") {
                    ((IfCommand*)commands.top())->addCommand(createLoopCommand(symbolTable, parts, commands, in));
                    commands.pop();
                } else if (typeid(commands.top()).name() == "LoopCommand") {
                    ((LoopCommand*)commands.top())->addCommand(createLoopCommand(symbolTable, parts, commands, in));
                    commands.pop();
                }
            } else {
                string str = findAndCreateTypeOfDefineVarCommand(symbolTable, parts);
                if (typeid(commands.top()).name() == "IfCommand") {
                    ((IfCommand*)commands.top())->addCommand(symbolTable->getCommandTable().at(str));
                } else if (typeid(commands.top()).name() == "LoopCommand") {
                    ((LoopCommand*)commands.top())->addCommand(symbolTable->getCommandTable().at(str));
                }
            }
        } else {
            throw "incomplete file";
        }
    }
    return commands.top();
}

void FunctionBundles::parser(string fileName, SymbolTable* symbolTable) {
    string line;
    ifstream in (fileName);
    if (in.is_open()) {
        while (getline(in, line)) {
            Lexer* lexer = new Lexer(line);
            vector<string> parts = lexer->lexerAlgorithem();
            if (parts[0] == "openDataServer") {
                int split = 1;
                Expression* port;
                Expression* frequency;
                for (int i = 1; i < parts.size() - 1; i++) {
                    if ((parts[i] == ")" && parts[i + 1] != "+" && parts[i + 1] != "-" && parts[i + 1] != "*" &&
                    parts[i + 1] != "/") || (parts[i] != "(" && parts[i] != ")" && parts[i] != "+" && parts[i] != "-" &&
                    parts[i] != "*" && parts[i] != "/" && parts[i + 1 ] != "(" && parts[i + 1 ] != ")" &&
                    parts[i + 1] != "+" && parts[i + 1] != "-" && parts[i + 1] != "*" && parts[i + 1] != "/")) {
                        split = i;
                        break;
                    }
                }
                port = createExpression(symbolTable->getCommandTable(), parts, 1, split + 1);
                frequency = createExpression(symbolTable->getCommandTable(), parts, split + 1, (int) parts.size());
                /*if ((int) port->calculate() >= 1024 || (int) port->calculate() <= 49151) {
                    throw "not in port range";
                }*/
                if (frequency->calculate() <= 0) {
                    throw "invalid frequency";
                }
                if (symbolTable->getCommandTable().find("openDataServer") == symbolTable->getCommandTable().end()) {
                    symbolTable->getCommandTable()["openDataServer"] = new OpenServerCommand((int) port->calculate(),
                            (int) frequency->calculate());
                } else {
                    ((OpenServerCommand*)symbolTable->getCommandTable()["openDataServer"])->setPort((int)
                    port->calculate());
                    ((OpenServerCommand*)symbolTable->getCommandTable()["openDataServer"])->setFrequency((int)
                    frequency->calculate());
                }
                symbolTable->getCommandTable()["openDataServer"]->execute();
            } else if (parts[0] == "connect") {
                Expression* port;
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
                port = createExpression(symbolTable->getCommandTable(), parts, 2, (int) parts.size());
                /*if (atoi(values[0].C_str()) > || atoi(values[0].c_str()) < ) {
                    throw "not in port range";
                }*/
                if (symbolTable->getCommandTable().find("connect") == symbolTable->getCommandTable().end()) {
                    symbolTable->getCommandTable().find("connect")->second = new ConnectCommand(parts[1], (int)
                    port->calculate());
                } else {
                    ((ConnectCommand*)symbolTable->getCommandTable()["connect"])->setIp(parts[1]);
                    ((ConnectCommand*)symbolTable->getCommandTable()["connect"])->setPort((int) port->calculate());
                }
                symbolTable->getCommandTable()["connect"]->execute();
            } else if (parts[0] == "if") {
                stack<Command*> commands;
                Command* ifCommand = createIfCommand(symbolTable, parts, commands, in);
                ifCommand->execute();
            } else if (parts[0] == "while") {
                stack<Command*> commands;
                Command* loopCommand = createLoopCommand(symbolTable, parts, commands, in);
                loopCommand->execute();
            } else {
                findAndCreateTypeOfDefineVarCommand(symbolTable, parts);
            }
        }
    }
}