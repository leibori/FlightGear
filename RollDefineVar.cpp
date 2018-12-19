#include "RollDefineVar.h"

int RollDefineVar::execute() {
    map<string, double>::iterator it = valuesMap->find("roll");
    if (it != valuesMap->end()) {
        it->second = roll;
    }
}