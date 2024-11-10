#include "gamemap.h"
#include <random>

/**
 * @brief Constructor for gamemap, initializes random boss room position and populates an array describing the map.
 * @author William Brewer
 */
Gamemap::Gamemap()
{
	// Initializations
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(1, 8);
	boss_pos = distr(eng);
	for (int i = 0; i < 9; i++)
	{
		bool boss = (i == boss_pos);

		map[i] = Room(boss);
	}
}

/**
 * @brief Constructor for gamemap, initializes random boss room position and populates an array describing the map.
 * @return map - the map array
 * @author William Brewer
 */
Room *Gamemap::getMap()
{
	return map;
}

int Gamemap::getBossRoom()
{

	return this->boss_pos;
}