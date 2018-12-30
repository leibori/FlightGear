cmake_minimum_required(VERSION 3.12)
project(project)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS  "-pthread")

add_executable(project main.cpp OpenServerCommand.h Command.h OpenServerCommand.cpp ConnectCommand.cpp
        ConnectCommand.h IfCommand.cpp IfCommand.h LoopCommand.cpp LoopCommand.h FuncCommand.cpp FuncCommand.h
        FunctionsBundle.cpp FunctionsBundle.h Expression.h ExpressionGenerator.cpp DefineVarCommand.h SymbolTable.h
        Lexer.cpp Lexer.h DefineVarCommand.cpp Add.cpp Add.h Sub.cpp Sub.h Mul.cpp Mul.h Div.cpp Div.h Number.cpp
        Number.h BinaryExpression.cpp BinaryExpression.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h
        SymbolTable.cpp UnaryExpression.cpp UnaryExpression.h Unequal.cpp Unequal.h Bigger.cpp Bigger.h Smaller.cpp
        Smaller.h Neg.cpp Neg.h Equal.cpp Equal.h CommandExpression.cpp CommandExpression.h DataReaderArguments.h
        DataReader.cpp DataReader.h Var.cpp Var.h BigEqual.cpp BigEqual.h SmallEqual.cpp SmallEqual.h)