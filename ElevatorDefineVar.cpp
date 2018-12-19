#include "ElevatorDefineVar.h"

int ElevatorDefineVar::execute() {
    map<string, double>::iterator it = valuesMap->find("elevator");
    if (it != valuesMap->end()) {
        it->second = elevator;
    }
}