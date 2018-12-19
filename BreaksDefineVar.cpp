#include "BreaksDefineVar.h"

int BreaksDefineVar::execute() {
    map<string, double>::iterator it = valuesMap->find("breaks");
    if (it != valuesMap->end()) {
        it->second = breaks;
    }
}