
#include "savefile.h"
using namespace std;

// Lorne Crewson 11/9/2021
/* SaveFile layout:
score       (int)
gamestatus  (boolean 1 or 0)
health      (int)
speed       (int)
strength    (int)

More to be added soon!
*/

int save(Game game, string file)
{
    string line;
    ofstream savefile(file);
    line = to_string(game.score);
    savefile << line << "\n";

    line = to_string(game.gameStatus);
    savefile << line << "\n";

    line = to_string(game.character.getHealth());
    savefile << line << "\n";

    line = to_string(game.character.getSpeed());
    savefile << line << "\n";

    line = to_string(game.character.getStrength());
    savefile << line << "\n";
    savefile.close();
    return 0;
}

Game load(string file)
{
    Game game;
    Character character;
    string line;
    ifstream savefile(file);

    getline(savefile, line);
    game.score = stoi(line);

    getline(savefile, line);
    game.gameStatus = (stoi(line) ? true : false);

    getline(savefile, line);
    character.setHealth(stoi(line));

    getline(savefile, line);
    character.setSpeed(stoi(line));

    getline(savefile, line);
    character.setStrength(stoi(line));

    game.character = character;
    savefile.close();

    return game;
}