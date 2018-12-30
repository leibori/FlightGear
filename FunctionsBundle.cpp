#include "FunctionsBundle.h"

/*
 * function name: createExpression
 * The function make exppression from the vector of string and take value from symbilTable ,by running from start to end
 **/
Expression *FunctionsBundle::createExpression(SymbolTable *symbolTable, vector<string> parts, int start, int end) {
    vector<string> value;
    for (int i = start; i < end; i++) {
        value.push_back(parts[i]);
    }
    //generate expression
    return expressionGenerator->generateExp(value, symbolTable);
}

/*
 * function name: findAndCreateTypeOfDefineVarCommand
 * The function find from symbolTable  and create var command by the string we got
 **/
Command *FunctionsBundle::findAndCreateTypeOfDefineVarCommand(SymbolTable *symbolTable, vector<string> parts) {
    if (parts[0] == "var") {
        // situation of var somthing without value
        if (parts.size() == 2) {
            //get value of zero
            Number *zero = new Number(0);
            DefineVarCommand *defineVarCommand = new DefineVarCommand(parts[1], zero, symbolTable);
            return defineVarCommand;
            // situation of var somthing with value
        } else if (parts[2] == "=") {
            // if its bind
            if (parts[3] == "bind") {
                string subStr = parts[4].substr(1, parts[4].size() - 2);
                DefineVarCommand *defineVarCommand = new DefineVarCommand(subStr, parts[1], symbolTable);
                return defineVarCommand;
            } else {
                //its expression and we make him as one
                Expression *expression = createExpression(symbolTable, parts, 3, (int) parts.size());
                DefineVarCommand *defineVarCommand = new DefineVarCommand(parts[1], expression, symbolTable);
                return defineVarCommand;
            }
        } else {
            throw "invalid initialization";
        }
        // not new initialization, puting value
    } else if (parts[1] == "=") {
        if (parts[2] == "bind") {
            //make bind value
            string subStr = parts[3].substr(1, parts[3].size() - 2);
            //checking in symbol table
            if (symbolTable->getValuesTable().find(parts[0]) != symbolTable->getValuesTable().end()) {
                DefineVarCommand *defineVarCommand = new DefineVarCommand(parts[0], parts[3], symbolTable);
                return defineVarCommand;
            } else {
                throw "variable wasn't initialized";
            }
        } else {
            //its expression
            Expression *expression = createExpression(symbolTable, parts, 2, (int) parts.size());
            DefineVarCommand *defineVarCommand = new DefineVarCommand(parts[0], expression, symbolTable);
            return defineVarCommand;
        }
    } else {
        throw "invalid initialization";
    }
}

/*
 * function name: createIfCommand
 * The function create command that is IfCommand
 **/
Command *FunctionsBundle::createIfCommand(SymbolTable *symbolTable, vector<string> parts, ifstream &in) {
    string line;
    Expression *condition;
    //start of condition
    if (parts[parts.size() - 1] == "{") {
        condition = createExpression(symbolTable, parts, 1, (int) (parts.size() - 1));
    } else {
        condition = createExpression(symbolTable, parts, 1, (int) parts.size());
        //reading
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
    //make it as Ifcommand
    IfCommand *ifCommand = new IfCommand(condition);
    //we didnt end the commends of the condition
    while (parts[0] != "}") {
        //reading
        if (getline(in, line)) {
            Lexer *lexer = new Lexer(line);
            parts = lexer->lexerAlgorithem();
            //checking what command is the string point to
            if (parts[0] == "if") {
                ifCommand->addCommand(createIfCommand(symbolTable, parts, in));
            } else if (parts[0] == "while") {
                ifCommand->addCommand(createLoopCommand(symbolTable, parts, in));
            } else if (parts[0] == "print") {
                ifCommand->addCommand(createPrintCommand(symbolTable, parts));
            } else if (parts[0] == "sleep") {
                ifCommand->addCommand(createSleepCommand(symbolTable, parts));
                //finish
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

/*
 * function name: createLoopCommand
 * The function create command that is LoopCommand
 **/
Command *FunctionsBundle::createLoopCommand(SymbolTable *symbolTable, vector<string> parts, ifstream &in) {
    string line;
    Expression *condition;
    //start of condition
    if (parts[parts.size() - 1] == "{") {
        condition = createExpression(symbolTable, parts, 1, (int) (parts.size() - 1));
    } else {
        condition = createExpression(symbolTable, parts, 1, (int) parts.size());
        //reading
        if (getline(in, line)) {
            Lexer *lexer = new Lexer(line);
            parts = lexer->lexerAlgorithem();
            //syntax error
            if (parts[0] != "{") {
                throw "invalid syntax";
            }
        } else {
            throw "incomplete file";
        }
    }
    LoopCommand *loopCommand = new LoopCommand(condition);
    //read all commends untill we finish the condition
    while (parts[0] != "}") {
        if (getline(in, line)) {
            Lexer *lexer = new Lexer(line);
            parts = lexer->lexerAlgorithem();
            //check commends inside
            if (parts[0] == "if") {
                loopCommand->addCommand(createIfCommand(symbolTable, parts, in));
            } else if (parts[0] == "while") {
                loopCommand->addCommand(createLoopCommand(symbolTable, parts, in));
            } else if (parts[0] == "print") {
                loopCommand->addCommand(createPrintCommand(symbolTable, parts));
            } else if (parts[0] == "sleep") {
                loopCommand->addCommand(createSleepCommand(symbolTable, parts));
                //we finish
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

/*
 * function name: createPrintCommand
 * The function create command that is PrintCommand
 **/
Command *FunctionsBundle::createPrintCommand(SymbolTable *symbolTable, vector<string> parts) {
    //check if we need to print string
    if (parts[1][0] == '"' && parts[1][parts[1].size() - 1] == '"') {
        //cut and send just the text
        string subStr = parts[1].substr(1, parts[1].size() - 2);
        PrintCommand *printCommand = new PrintCommand(subStr);
        return printCommand;
    } else {
        //print as expression
        Expression *expression = createExpression(symbolTable, parts, 1, (int) parts.size());
        PrintCommand *printCommand = new PrintCommand(expression);
        return printCommand;
    }
}

/*
 * function name: createSleepCommand
 * The function create command that is SleepCommand
 **/
Command *FunctionsBundle::createSleepCommand(SymbolTable *symbolTable, vector<string> parts) {
    Expression *expression = createExpression(symbolTable, parts, 1, (int) parts.size());
    if (expression->calculate() >= 0) {
        SleepCommand *sleepCommand = new SleepCommand(expression);
        return sleepCommand;
    } else {
        throw "can't sleep a negative amount of time";
    }
}

/*
 * function name: parser
 * The function get string name of command or expression, put value if nedded and add it to correct map
 **/
void FunctionsBundle::parser(string fileName, SymbolTable *symbolTable) {
    bool didOpenServer = false;
    ifstream in(fileName);
    if (!in.is_open()) { return; }
    string line;
    OpenServerCommand *openServerCommand;
    ConnectCommand *connectCommand;
    //reading file
    while (getline(in, line)) {
        Lexer *lexer = new Lexer(line);
        vector<string> parts = lexer->lexerAlgorithem();
        //checking the command
        if (parts[0] == "openDataServer") {
            int split = 1;
            Expression *port;
            Expression *frequency;
            for (int i = 1; i < parts.size() - 1; i++) {
                //check where to split
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
            //checking max and min value of port
            if ((int) port->calculate() < 1024 || (int) port->calculate() > 65535) {
                throw "not in port range";
            }
            //checking  correction of frequancy
            if (frequency->calculate() <= 0) {
                throw "invalid frequency";
            }
            openServerCommand = new OpenServerCommand(symbolTable, (int) port->calculate(),
                                                      (int) frequency->calculate());
            openServerCommand->execute();
            //we open server
            didOpenServer = true;
        } else if (parts[0] == "connect") {
            if (!didOpenServer) {
                throw "did not open a server to connect to";
            }
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
            //not by correct values
            if ((int) port->calculate() < 1024 || (int) port->calculate() > 65535) {
                throw "not in port range";
            }
            connectCommand = new ConnectCommand(parts[1], (int) port->calculate(), &symbolTable->isServerOpen);
            connectCommand->execute();
            symbolTable->setConnectCommand(connectCommand);
            //checking fot other commends
        } else if (parts[0] == "if") {
            Command *ifCommand = createIfCommand(symbolTable, parts, in);
            ifCommand->execute();
            delete ifCommand;
        } else if (parts[0] == "while") {
            Command *loopCommand = createLoopCommand(symbolTable, parts, in);
            loopCommand->execute();
            delete loopCommand;
        } else if (parts[0] == "print") {
            Command *printCommand = createPrintCommand(symbolTable, parts);
            printCommand->execute();
            delete printCommand;
        } else if (parts[0] == "sleep") {
            Command *sleepCommand = createSleepCommand(symbolTable, parts);
            sleepCommand->execute();
            delete sleepCommand;
            //its defineVarCommand , we need to check which one and create it
        } else {
            Command *defineVarCommand = findAndCreateTypeOfDefineVarCommand(symbolTable, parts);
            defineVarCommand->execute();
            delete defineVarCommand;
        }
    }
    in.close();
    symbolTable->isServerOpen = false;


}

FunctionsBundle::~FunctionsBundle() {
delete expressionGenerator;
}
