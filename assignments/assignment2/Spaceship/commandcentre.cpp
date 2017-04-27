#include "commandcentre.h"

namespace si {

    /**
     * \brief: Puts the current command at the back of the queue
     * \param: s, the current command, could be "Left", "Right", "Fire"
     */
    void CommandCentre::addToBuffer(std::string s)
    {
        m_commandBuffer.push_back(s);
    }

    /**
     * \brief: Used so that we don't accidentally try to access data
     *         in the queue if the queue is empty
     * \result: true if there is more data in the queue
     */
    bool CommandCentre::hasNext() const
    {
        if (m_commandBuffer.empty()) {
            return false;
        } else {
            return true;
        }
    }

    /**
     * \brief: Removes the last element in the queue. Undefined behaviour
     *         if the queue is empty, so please call hasNext() first.
     * \result: the next command in the queue
     */
    std::string CommandCentre::popNext()
    {
        std::string firstElement = m_commandBuffer.front();
        // Delete the first element
        m_commandBuffer.erase(m_commandBuffer.begin());
        return firstElement;
    }

} // end namespace si
