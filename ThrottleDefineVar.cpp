#include "ThrottleDefineVar.h"

int ThrottleDefineVar::execute() {
    map<string, double>::iterator it = valuesMap->find("throttle");
    if (it != valuesMap->end()) {
        it->second = throttle;
    }
}