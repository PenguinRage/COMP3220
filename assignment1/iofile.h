#ifndef IOFILE_H
#define IOFILE_H

#include <fstream>
#include <string>

namespace io {
    const std::string CONFIG_PATH = "/home/penguinrage/repositories/COMP3220/assignment1/invaders.cfg";
    class IOFile {
    public:
        IOFile() { readFile(); }
        void readFile();
        void validateFile();
        bool isInt(std::string s);
        std::string removeSpace(std::string);
        std::string intToString(int number);

        int getSize(){ return size; }
        int getXPos(){ return xPos; }


    private:
        int size;
        int xPos;

    };
}

#endif // IOFILE_H
