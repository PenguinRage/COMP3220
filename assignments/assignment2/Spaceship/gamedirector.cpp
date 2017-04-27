#include "gamedirector.h"

#include "commandcentre.h"
#include "iofile.h"

namespace si {

    /**
     * \brief: Basic game creation, there may be more of these methods if
     *         more levels are added to the game.
     * \result: builder, the builder helper used to create the game object
     */
    BattleSphere* GameDirector::createBattleSphereStandardMode(BattlesphereBuilder& builder)
    {
        // Read the IO file inside here
        //IOFile ioFile("config.ini");
        IOFile* ioFile = IOFile::getInstance("../Spaceship/config.ini");
        CommandCentre commandCentre = ioFile->getCommandCentre();
        Defender defender = ioFile->getDefender();

        builder.buildDefender(defender);
        builder.buildBulletParameters(40);
        builder.buildCommandCentre(commandCentre);

        delete ioFile;
        return builder.getBattlesphere();
    }

} // end namespace si
