#include "iofile.h"

namespace si {

    IOFile* IOFile::instance = 0;

    /**
     * \brief: Singleton instance getter. Ensures we do not create more than one
     *         IOFile.
     * \param: fileName, the path to the file. Will work with just the name of the
     *          file if the file is placed inside the build directory created by QT.
     */
    IOFile* IOFile::getInstance(std::string fileName)
    {
        if (0 == instance) {
            instance = new IOFile(fileName);
        }
        return instance;
    }

    /**
     * \brief: Protected singleton constructor. End-users cannot access this.
     * \param: fileName, the path to the file. Will work with just the name of the
     *          file if the file is placed inside the build directory created by QT.
     */
    IOFile::IOFile(std::string fileName)
        : m_fileName(fileName),
          m_numberOfLines(0)
    {
        std::string line;
        std::vector<std::string> lines;
        std::ifstream inputStream (m_fileName);

        if (inputStream.is_open())
        {
            while( std::getline(inputStream, line) )
            {
                if (!line.empty()) {
                    lines.push_back(line);
                    m_numberOfLines++;
                }
            }
            inputStream.close();
            processLines(lines);
        } else {
            std::cout << "Error opening file! Is" <<
                         " it called config.ini and is it " <<
                         "placed inside the source directory, " <<
                         "named info3220_assignment1-master?" << std::endl;
        }
    }

    /**
     * \brief: Used to vet the lines returned from the config.ini file.
     * \param: lines, each element is a line in the input file (config.ini)
     * \result: true if the file format is valid, false if there is a problem.
     *          This function will also print to stdout if there is a problem.
     */
    bool IOFile::processLines(const std::vector<std::string>& lines)
    {
        if (lines.size() < 5) {
            std::cout << "ERROR: Not enought lines in input file" << std::endl;
            return false;
        }

        if (lines.at(0) != "[ Defender ]") {
            std::cout << "ERROR: First line must read [ Defender ]" << std::endl;
            return false;
        }

        // X coordinate check
        if (isValidCoordinateCommand(lines.at(1), true)) {
            int xCoordinate = getCoordinate(lines.at(1));
            m_defender.setX(xCoordinate);
            std::cout << "X coord is : " << xCoordinate << std::endl;
        } else {
            return false;
        }

        // Y coordinate check
        if (isValidCoordinateCommand(lines.at(2), false)) {
            int yCoordinate = getCoordinate(lines.at(2));
            m_defender.setY(yCoordinate);
            std::cout << "Y coord is: " << yCoordinate << std::endl;
        } else {
            return false;
        }

        // Scale check
        if (isValidScaleCommand((lines.at(3)))) {
            std::string scale = getScale(lines.at(3));
            m_defender.setScale(scale);
        } else {
            return false;
        }

        if (lines.at(4) != "[ Commands ]") {
            std::cout << "ERROR: 4th line must read [ Commands ]" << std::endl;
            return false;
        }

        std::vector<std::string> commands(lines.begin()+5, lines.end());

        std::regex e ("Left|Right|Fire");
        for (auto &curLine : commands) {
            if (!std::regex_match(curLine, e)) {
                std::cout << "Error: Commands must only be 'Left', 'Right', or 'Fire'" << std::endl;
                return false;
            }
            m_commandCentre.addToBuffer(curLine);
        }

        return true;
    }

    /**
     * \brief: Uses regex to check that defender coordinates are written in config.ini
     *         in the format XPos = 120 or YPos = 100 (of course the user can pick their
     *         own values for XPos and YPos, the numbers above are only illustrative.
     * \param: line, a line of the input file to be checked (config.ini)
     * \param: isX, true if we are checking whether this is a valid x coordinate command,
     *              false if we are checking whether this is a valid y coordinate command.
     * \result: true if the regex matches the line in the file, false otherwise
     */
    bool IOFile::isValidCoordinateCommand(std::string line, bool isX)
    {
        std::string label = "XPos";
        if (!isX) {
            label = "YPos";
        }
        std::regex e (label + "\\s*=\\s*\\d+$");
        if (std::regex_match(line, e)) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * \brief: Checks that the scale command is written in the file as Scale = tiny
     *          (for example)
     * \param: line, a line in our input file
     * \result: true if the regex matches the scale line in the input file (config.ini)
     */
    bool IOFile::isValidScaleCommand(std::string line)
    {
        std::regex e ("Scale\\s*=\\s*[a-z]+$");
        if (std::regex_match(line, e)) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * \brief: Extracts the integer value from a line such as "XPos = 123". Would
     *         return 123 in this case.
     * \param: line, a coordinate line in our input file (config.ini)
     * \result: the integer value extracted from that line
     */
    int IOFile::getCoordinate(std::string line)
    {
        // Match numbers
        std::regex e ("\\d+");
        std::smatch m;
        if (std::regex_search (line, m, e)) {
          return std::stoi(m[0]);
        } else {
            // Do some error handling and return 0
            std::cout << "Could not parse: " << line << std::endl;
            std::cout << "Using default value of 0" << std::endl;
            return 0;
        }
    }

    /**
     * \brief: Extracts the scale string from a line in the input file, such as
     *         "Scale = tiny".
     * \param: line, a line in the input (config.ini) file
     * \result: the scale as a string, would return "tiny" in the above example
     */
    std::string IOFile::getScale(std::string line)
    {
        // Match numbers
        std::regex e ("tiny|normal|large|giant");
        std::smatch m;
        if (std::regex_search (line, m, e)) {
          return m[0];
        } else {
            // Do some error handling and return "tiny"
            std::cout << "Could not parse: " << line << std::endl;
            std::cout << "Using default value of tiny" << std::endl;
            return "tiny";
        }
    }

    /**
     * \brief: Returns a buffer of commands obtained from config.ini
     * \result: a command centre instance
     */
    const CommandCentre& IOFile::getCommandCentre() const
    {
        return m_commandCentre;
    }

    /**
     * \brief: Returns a player (Defender) object based on information supplied in config.ini
     * \result: a defender instance, ready to be used in a BattleSphere
     */
    const Defender& IOFile::getDefender() const
    {
        return m_defender;
    }

} // end namespace si
