// SAVEFILE.h
#ifndef SAVEFILE_H // include guard
#define SAVEFILE_H
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "game.cpp"
#include <string>
#include "character.cpp"
class SaveFile
{
public:
    int save(Game game, string file);
    Game load(string file);
};

#endif /* SAVEFILE_H */