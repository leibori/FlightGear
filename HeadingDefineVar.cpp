#include "HeadingDefineVar.h"

int HeadingDefineVar::execute() {
    map<string, double>::iterator it = valuesMap->find("heading");
    if (it != valuesMap->end()) {
        it->second = heading;
    }
}