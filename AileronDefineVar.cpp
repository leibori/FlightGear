#include "AileronDefineVar.h"

int AileronDefineVar::execute() {
    map<string, double>::iterator it = valuesMap->find("aileron");
    if (it != valuesMap->end()) {
        it->second = aileron;
    }
}