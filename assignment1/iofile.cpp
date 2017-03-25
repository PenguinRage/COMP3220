#include "iofile.h"
#include <iostream>

using namespace std;

void io::IOFile::readFile(){
    ifstream file(CONFIG_PATH.c_str());
    string buffer;
    string buffer2;

    // No config case
    if (file.fail()) {
        cout << "No configuration file found" << std::endl;
        exit(0);
    }

    if (file.is_open()){
        string placeholder = "";
        // Get lines of file
        while(getline(file, buffer)) {
            // ignore blank lines
            if (buffer.length()) contine;
            // ignore comments
            if (buffer[0] =='#') contine;
            // find delimiter index
            int indexOfColon = buffer.find(":");

        }
    }
}
