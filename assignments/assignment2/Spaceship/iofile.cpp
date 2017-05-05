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
    if (isValidCommand(lines.at(1), "XPos")) {
        int xCoordinate = getCoordinate(lines.at(1));
        m_defender.setX(xCoordinate);
        std::cout << "X coord is : " << xCoordinate << std::endl;
    } else {
        return false;
    }

    // Y coordinate check
    if (isValidCommand(lines.at(2), "YPos")) {
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
    int line_count = 4;

    std::regex r ("Left|Right|Up|Down");

    // Extension to import alien swarms from config
    if (lines.at(line_count) == "[ Aliens ]") {
        line_count++;
        int num_of_swarms;
        if (isValidCommand(lines.at(line_count), "swarms")) {
            num_of_swarms = getCoordinate(lines.at(line_count));
            std::cout << "number of swarms is : " << num_of_swarms << std::endl;
            std::cout << "Alien ids are in the range between 1 and " << num_of_swarms << " inclusive" << std::endl;
        }
        // Check swarms are actually available given the flag aliens
        if (num_of_swarms==0)
        {
            std::cout << "ERROR: Number of swarms must be greater than 0" << std::endl;
            return false;
        }
        for (int i = 0; i < num_of_swarms; i++)
        {
            m_swarm.push_back(Swarm());
        }

        line_count++;
        int XMat, YMat, XDel, YDel;
        // Get starting X position of Matrix Swarms
        if (isValidCommand(lines.at(line_count), "XMat")) {
            XMat = getCoordinate(lines.at(line_count));
            std::cout << "Matrix Start X is : " << XMat << std::endl;
        }
        line_count++;
        // Get starting Y position of Matrix Swarms
        if (isValidCommand(lines.at(line_count), "YMat")) {
            YMat = getCoordinate(lines.at(line_count));
            std::cout << "Matrix Start Y is : " << YMat << std::endl;
        }

        line_count++;
        // Get X Delimiter
        if (isValidCommand(lines.at(line_count), "XDel")) {
            XDel = getCoordinate(lines.at(line_count));
            std::cout << "Matrix delimiter X is : " << XDel << std::endl;
        }
        line_count++;
        // Get Y Delimiter
        if (isValidCommand(lines.at(line_count), "YDel")) {
            YDel = getCoordinate(lines.at(line_count));
            std::cout << "Matrix delimiter Y is : " << YDel << std::endl;
        }
        line_count++;

        // Next is the Alien sequence laid out in form of matrix
        std::vector<std::string> swarm(lines.begin()+line_count, lines.end());
        int count_y = 0;
        for (auto &curLine : swarm)
        {
            if (curLine == "[ 1 ]") break;

            line_count++;

            int count_x = 0;
            int y = YMat + count_y * YDel;
            for (char &c : curLine)
            {
                int x = XMat + count_x * XDel;
                int a = c - '0';
                if ((a-1) == -1)
                {

                    count_x++;
                    continue;
                }
                else if ((a-1) > -1 && (a-1) < 9)
                {
                    Alien curAlien(x,y,a);
                    m_swarm[(a-1)].add(curAlien);
                }
                else
                {
                    std::cout << "ERROR: Line " << line_count << " needs to contain the correct alien sequence" << std::endl;
                    return false;
                }
                count_x++;
            }
            count_y++;
        }

        // Get Trajectory for each swarm
        std::vector<std::string> trajectory(lines.begin()+line_count, lines.end());
        int i = 1;
        for (auto &curLine : trajectory)
        {
            if (curLine == "[ Commands ]") break;

            std::stringstream ss;
            ss << "[ " << i << " ]";
            if (curLine != ss.str())
            {
                if (!std::regex_match(curLine, r)) {
                    if (i == m_swarm.size())
                    {
                        std::cout << "ERROR: Line " << line_count << " swarm trajectory for swarm id: " << (i+1) << " is unsupported" << std::endl;
                        return false;
                    }
                    i++;
                }
                {
                    m_swarm[(i-1)].addTrajectory(curLine);
                }
            }

            line_count++;
        }
    }

    std::regex e ("Left|Right|Fire");
    // Get the commands
    if (lines.at(line_count) != "[ Commands ]") {
        std::cout << "ERROR: Line " << line_count << " must read [ Commands ]" << std::endl;
        return false;
    }

    line_count++;
    std::vector<std::string> commands(lines.begin()+line_count, lines.end());


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
bool IOFile::isValidCommand(std::string line, std::string label)
{
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

const std::vector<Swarm>& IOFile::getSwarm() const
{
    return m_swarm;
}

} // end namespace si
