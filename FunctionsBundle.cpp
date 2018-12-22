#include "FunctionsBundle.h"

string FunctionBundles::replaceStringWithValue(map<string,double> newValues, string str) {
    if (newValues.find(str) != newValues.end()) {
        return to_string(newValues.at(str));
    }
    return str;
}

Expression* FunctionBundles::createExpression(map<string,Command*> commandTable, map<string,double> newValues,
        vector<string> parts, int start, int end) {
    ExpressionGenerator expressionGenerator;
    vector<string> value;
    for ( int i = start; i < end; i++) {
        value.push_back(replaceStringWithValue(newValues, parts[i]));
    }
    return expressionGenerator.generateExp(value, commandTable);
}

void FunctionBundles::inputToSymbolMap(SymbolTable* symbolTable, map<string,double> newValues, string str, Expression*
expression) {
    if (symbolTable->getInitializeTable().find(str) == symbolTable->getInitializeTable().end()) {
        if (str == "aileron") {
            if (symbolTable->getInitializeTable().at(str) == true) {
                ((AileronDefineVar*)symbolTable->getCommandTable()[str])->setAileron(expression->calculate());
                symbolTable->getCommandTable()[str]->execute();
            } else {
                AileronDefineVar* aileronDefineVar = new AileronDefineVar(expression->calculate(), symbolTable);
                aileronDefineVar->execute();
            }
        } else if (str == "airspeed") {
            if (symbolTable->getInitializeTable().at(str) == true) {
                ((AirspeedDefineVar*)symbolTable->getCommandTable()[str])->setAirspeed(expression->calculate());
                symbolTable->getCommandTable()[str]->execute();
            } else {
                AirspeedDefineVar* airspeedDefineVar = new AirspeedDefineVar(expression->calculate(), symbolTable);
                airspeedDefineVar->execute();
            }
        } else if (str == "alt") {
            if (symbolTable->getInitializeTable().at(str) == true) {
                ((AltDefineVar*)symbolTable->getCommandTable()[str])->setAlt(expression->calculate());
                symbolTable->getCommandTable()[str]->execute();
            } else {
                AltDefineVar* altDefineVar = new AltDefineVar(expression->calculate(), symbolTable);
                altDefineVar->execute();
            }
        } else if (str == "breaks") {
            if (symbolTable->getInitializeTable().at(str) == true) {
                ((BreaksDefineVar*)symbolTable->getCommandTable()[str])->setBreaks(expression->calculate());
                symbolTable->getCommandTable()[str]->execute();
            } else {
                BreaksDefineVar* breaksDefineVar = new BreaksDefineVar(expression->calculate(), symbolTable);
                breaksDefineVar->execute();
            }
        } else if (str == "elevator") {
            if (symbolTable->getInitializeTable().at(str) == true) {
                ((ElevatorDefineVar*)symbolTable->getCommandTable()[str])->setElevator(expression->calculate());
                symbolTable->getCommandTable()[str]->execute();
            } else {
                ElevatorDefineVar* elevatorDefineVar = new ElevatorDefineVar(expression->calculate(), symbolTable);
                elevatorDefineVar->execute();
            }
        } else if (str == "heading") {
            if (symbolTable->getInitializeTable().at(str) == true) {
                ((HeadingDefineVar*)symbolTable->getCommandTable()[str])->setHeading(expression->calculate());
                symbolTable->getCommandTable()[str]->execute();
            } else {
                HeadingDefineVar* headingDefineVar = new HeadingDefineVar(expression->calculate(), symbolTable);
                headingDefineVar->execute();
            }
        } else if (str == "pitch") {
            if (symbolTable->getInitializeTable().at(str) == true) {
                ((PitchDefineVar*)symbolTable->getCommandTable()[str])->setPitch(expression->calculate());
                symbolTable->getCommandTable()[str]->execute();
            } else {
                PitchDefineVar* pitchDefineVar = new PitchDefineVar(expression->calculate(), symbolTable);
                pitchDefineVar->execute();
            }
        } else if (str == "roll") {
            if (symbolTable->getInitializeTable().at(str) == true) {
                ((RollDefineVar*)symbolTable->getCommandTable()[str])->setRoll(expression->calculate());
                symbolTable->getCommandTable()[str]->execute();
            } else {
                RollDefineVar* rollDefineVar = new RollDefineVar(expression->calculate(), symbolTable);
                rollDefineVar->execute();
            }
        } else if (str == "rudder") {
            if (symbolTable->getInitializeTable().at(str) == true) {
                ((RudderDefineVar*)symbolTable->getCommandTable()[str])->setRudder(expression->calculate());
                symbolTable->getCommandTable()[str]->execute();
            } else {
                RudderDefineVar* rudderDefineVar = new RudderDefineVar(expression->calculate(), symbolTable);
                rudderDefineVar->execute();
            }
        } else if (str == "throttle") {
            if (symbolTable->getInitializeTable().at(str) == true) {
                ((ThrottleDefineVar *) symbolTable->getCommandTable()[str])->setThrottle(expression->calculate());
                symbolTable->getCommandTable()[str]->execute();
            } else {
                ThrottleDefineVar *throttleDefineVar = new ThrottleDefineVar(expression->calculate(), symbolTable);
                throttleDefineVar->execute();
            }
        }
    } else {
        map<string, double>::iterator it = newValues.find(str);
        if (it != newValues.end()) {
            it->second = expression->calculate();
        }
    }
}

string FunctionBundles::findAndCreateTypeOfDefineVarCommand(SymbolTable* symbolTable, map<string,double> newValues,
        vector<string> parts) {
    if (parts[0] == "var" && parts[2] == "=") {
        if (parts[3] == "bind") {

        } else {
            Expression* expression = createExpression(symbolTable->getCommandTable(), newValues, parts, 3, (int) parts
            .size());
            if (symbolTable->getInitializeTable().find(parts[1]) == symbolTable->getInitializeTable().end()) {
                newValues.insert(pair<string, double>(parts[1], 0));
            }
            inputToSymbolMap(symbolTable, newValues, parts[1], expression);
            return parts[1];
        }
    } else if (parts[1] == "=") {
        if (parts[2] == "bind") {

        } else {
            Expression* expression = createExpression(symbolTable->getCommandTable(), newValues, parts, 2, (int) parts
            .size());
            if (symbolTable->getInitializeTable().at(parts[0]) == true || newValues.find(parts[0]) != newValues.end()) {
                inputToSymbolMap(symbolTable, newValues, parts[0], expression);
                return parts[0];
            } else {
                throw "DefineVarCommand not initialized";
            }
        }
    }
}

Command* FunctionBundles::createIfCommand(SymbolTable* symbolTable, map<string,double> newVariables, vector<string>
        parts, stack<Command*> commands, ifstream& in) {
    string line;
    Expression* condition;
    if (parts[parts.size() - 1] == "{") {
        condition = createExpression(symbolTable->getCommandTable(), newVariables, parts, 1, (int) (parts.size() - 1));
    } else {
        condition = createExpression(symbolTable->getCommandTable(), newVariables, parts, 1, (int) parts.size());
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
                    ((IfCommand*)commands.top())->addCommand(createIfCommand(symbolTable, newVariables, parts,
                            commands, in));
                    commands.pop();
                } else if (typeid(commands.top()).name() == "LoopCommand") {
                    ((LoopCommand*)commands.top())->addCommand(createIfCommand(symbolTable, newVariables, parts,
                            commands, in));
                    commands.pop();
                }
            } else if (parts[0] == "while") {
                if (typeid(commands.top()).name() == "IfCommand") {
                    ((IfCommand*)commands.top())->addCommand(createLoopCommand(symbolTable, newVariables, parts,
                            commands, in));
                    commands.pop();
                } else if (typeid(commands.top()).name() == "LoopCommand") {
                    ((LoopCommand*)commands.top())->addCommand(createLoopCommand(symbolTable, newVariables, parts,
                            commands, in));
                    commands.pop();
                }
            } else {
                string str = findAndCreateTypeOfDefineVarCommand(symbolTable, newVariables, parts);
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

Command* FunctionBundles::createLoopCommand(SymbolTable* symbolTable, map<string,double> newVariables, vector<string>
        parts, stack<Command*> commands, ifstream& in) {
    string line;
    Expression* condition;
    if (parts[parts.size() - 1] == "{") {
        condition = createExpression(symbolTable->getCommandTable(), newVariables, parts, 1, (int) (parts.size() - 1));
    } else {
        condition = createExpression(symbolTable->getCommandTable(), newVariables, parts, 1, (int) parts.size());
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
                    ((IfCommand*)commands.top())->addCommand(createIfCommand(symbolTable, newVariables, parts,
                                                                             commands, in));
                    commands.pop();
                } else if (typeid(commands.top()).name() == "LoopCommand") {
                    ((LoopCommand*)commands.top())->addCommand(createIfCommand(symbolTable, newVariables, parts,
                                                                               commands, in));
                    commands.pop();
                }
            } else if (parts[0] == "while") {
                if (typeid(commands.top()).name() == "IfCommand") {
                    ((IfCommand*)commands.top())->addCommand(createLoopCommand(symbolTable, newVariables, parts,
                                                                               commands, in));
                    commands.pop();
                } else if (typeid(commands.top()).name() == "LoopCommand") {
                    ((LoopCommand*)commands.top())->addCommand(createLoopCommand(symbolTable, newVariables, parts,
                                                                                 commands, in));
                    commands.pop();
                }
            } else {
                string str = findAndCreateTypeOfDefineVarCommand(symbolTable, newVariables, parts);
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
        map<string,double> newVariables = {};
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
                port = createExpression(symbolTable->getCommandTable(), newVariables, parts, 1, split + 1);
                frequency = createExpression(symbolTable->getCommandTable(), newVariables, parts, split + 1,
                        (int) parts.size());
                /*if ((int) port->calculate() >= 1024 || (int) port->calculate() <= 49151) {
                    throw "not in port range";
                }*/
                if (frequency->calculate() <= 0) {
                    throw "invalid frequency";
                }
                if (symbolTable->getInitializeTable()["openDataServer"] == false) {
                    symbolTable->getCommandTable()["openDataServer"] = new OpenServerCommand((int) port->calculate(),
                            (int) frequency->calculate());
                    symbolTable->getInitializeTable()["openDataServer"] = true;
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
                port = createExpression(symbolTable->getCommandTable(), newVariables, parts, 2, (int) parts.size());
                /*if (atoi(values[0].C_str()) > || atoi(values[0].c_str()) < ) {
                    throw "not in port range";
                }*/
                if (symbolTable->getInitializeTable()["connect"] == false) {
                    symbolTable->getCommandTable().find("connect")->second = new ConnectCommand(parts[1], (int)
                    port->calculate());
                    symbolTable->getInitializeTable()["connect"] = true;
                } else {
                    ((ConnectCommand*)symbolTable->getCommandTable()["connect"])->setIp(parts[1]);
                    ((ConnectCommand*)symbolTable->getCommandTable()["connect"])->setPort((int) port->calculate());
                }
                symbolTable->getCommandTable()["connect"]->execute();
            } else if (parts[0] == "if") {
                stack<Command*> commands;
                Command* ifCommand = createIfCommand(symbolTable, newVariables, parts, commands, in);
                ifCommand->execute();
            } else if (parts[0] == "while") {
                stack<Command*> commands;
                Command* loopCommand = createLoopCommand(symbolTable, newVariables, parts, commands, in);
                loopCommand->execute();
            } else {
                findAndCreateTypeOfDefineVarCommand(symbolTable, newVariables, parts);
            }
        }
    }
}