#include "RudderDefineVar.h"

int RudderDefineVar::execute() {
    map<string, double>::iterator it = valuesMap->find("rudder");
    if (it != valuesMap->end()) {
        it->second = rudder;
    }
}