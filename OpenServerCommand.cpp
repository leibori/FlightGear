#include "OpenServerCommand.h"

using namespace std;

void OpenServerCommand::execute() {


    auto *args = new DataReaderArguments(port, frequency, symbolTable);

    const DataReader dataReader;
    pthread_t pthread;
    pthread_create(&pthread, nullptr, DataReader::openServer, (void*)args);

    this_thread::__sleep_for(std::chrono::seconds(0),std::chrono::milliseconds(100));
}
