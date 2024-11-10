// ROOM.h
#ifndef GAMEMAP_H //include guard
#define GAMEMAP_H

#include <string>
#include "room.h"

/**
 * @brief Gamemap class, encapsulates the game map with an array describing the map
 * @author William Brewer
 */
class Gamemap
{
    private:
        Room map[9];
        int boss_pos;
    public:
        Gamemap();
		Room* getMap();
        int getBossRoom();
};

#endif /* GAMEMAP_H */