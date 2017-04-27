#ifndef IOFILE_H
#define IOFILE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>

#include "commandcentre.h"
#include "defender.h"

namespace si {

    class IOFile
    {
    public:
        static IOFile* getInstance(std::string fileName);

        ~IOFile(){}

        void addElement(std::string section, std::string key, std::string value);

        void updateElement(std::string section, std::string key, std::string value);

        std::string& getElement(std::string section, std::string key);

        const CommandCentre& getCommandCentre() const;

        const Defender& getDefender() const;

    protected:
        IOFile(std::string fileName);

    private:
        static IOFile* instance;
        bool processLines(const std::vector<std::string>& lines);

        // Checks that coordinate lines are in correct format (XPos = 140)
        // is isX, then uses "XPos" as label, otherwise uses "YPos" as label
        static bool isValidCoordinateCommand(std::string line, bool isX);

        static bool isValidScaleCommand(std::string line);

        // Gets '140' from 'XPos = 140' or 'YPos = 140'
        static int getCoordinate(std::string line);

        static std::string getScale(std::string line);

        int m_numberOfLines;
        Defender m_defender;
        CommandCentre m_commandCentre;

        std::string m_fileName;
    };

} // end namespace si

#endif // IOFILE_H
