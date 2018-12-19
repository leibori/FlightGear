#include "AltDefineVar.h"

int AltDefineVar::execute() {
    map<string, double>::iterator it = valuesMap->find("alt");
    if (it != valuesMap->end()) {
        it->second = alt;
    }
}