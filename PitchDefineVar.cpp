#include "PitchDefineVar.h"

int PitchDefineVar::execute() {
    map<string, double>::iterator it = valuesMap->find("pitch");
    if (it != valuesMap->end()) {
        it->second = pitch;
    }
}