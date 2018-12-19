#include "AirspeedDefineVar.h"

int AirspeedDefineVar::execute() {
    map<string, double>::iterator it = valuesMap->find("airspeed");
    if (it != valuesMap->end()) {
        it->second = airspeed;
    }
}