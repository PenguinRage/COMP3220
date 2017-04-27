#ifndef COMMANDCENTRE_H
#define COMMANDCENTRE_H

#include <vector>
#include <string>

namespace si {

    class CommandCentre
    {
    public:
        CommandCentre(){}
        ~CommandCentre(){}

        void addToBuffer(std::string s);
        bool hasNext() const;
        std::string popNext();

    private:
        std::vector<std::string> m_commandBuffer;
    };

} // end namespace si

#endif // COMMANDCENTRE_H
