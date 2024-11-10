// ROOM.h
#ifndef ROOM_H //include guard
#define ROOM_H

#include <string>

/**
 * @brief Room class, encapsulates room objects describing their information
 * @author William Brewer
 */
class Room
{
    private:
        int num_enemies;
        int num_powerups;
        bool boss_room;
        bool lock_status;
    
    public:
		Room();
		Room(bool is_boss);
        bool getBossRoom();
        void setLockStatus(bool locked);
        bool getLockStatus();
        int getNumEnemies();
        int getNumPowerups();
        void lowerEnemyNumber();
};

#endif /* ROOM_H */