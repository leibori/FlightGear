#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command(){};
};

#endif //PROJECT_COMMAND_H
