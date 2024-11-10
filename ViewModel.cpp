#include "ViewModel.h"

/**
 * @brief Generate new generic ViewModel with a default enemy and default amount of bullets.
 * @author Lorne Crewson
 */
ViewModel::ViewModel()

{
    //this->map = Gamemap();
    this->map_info = map.getMap();
    for (int i = 0; i < bulletNumber; i++)
    {
        Bullet b;
        bullets[i] = b;
    }
    for (int i = 0; i < enemyNumber; i++)
    {
        Enemy e;
        e.setEmpty(false);
        e.setEnemyType(i % 8);
        e.setpos(sf::Vector2f(100, 100));
        enemies[i] = e;
    }
    enemies[map.getBossRoom()].setEmpty(true);
    boss.setpos(sf::Vector2f(100, 100));
    for (int i = 0; i < powerNumber; i++)
    {
        powerUp p = powerUp(i % 3);
        p.setEmpty(false);
        pUps[i] = p;
    }
    sf::Texture t;
    if (!t.loadFromFile("health128.png"))
    {
        // error...
    }
    for (int i = 0; i < character.getTotalHealth(); i++)
    {
        sf::Sprite h;
        h.setTexture(t);
        h.setPosition(0 + i * 64, 0);
        h.setScale(0.5, 0.5);
        health[i] = h;
    }
}
/**
 * @brief Generate new custom ViewModel() with roomNum rooms, enemyType enemy and enemy with enemyHeal health.
 * @param roomNum - The number of rooms in the map
 * @param enemyHeal - Enemy health level
 * @param enemyType - type of enemy
 * @author Lorne Crewson
 */
ViewModel::ViewModel(int roomNum, int enemyHeal, int enemyType)

{
    roomNumber = roomNum;
    enemyHealth = enemyHeal;
    //setRoomNumber(roomNum);
    //setEnemyNumber(enemyNumber);
    for (int i = 0; i < bulletNumber; i++)
    {
        Bullet b;
        bullets[i] = b;
    }
    for (int i = 0; i < enemyNumber; i++)
    {
        Enemy e;
        e.setEmpty(false);
        e.setEnemyType(enemyType);
        enemies[i] = e;
    }
    for (int i = 0; i < powerNumber; i++)
    {
        powerUp p = powerUp(i % 3);
        p.setEmpty(false);
        pUps[i] = p;
    }
    sf::Texture t;
    if (!t.loadFromFile("health.png"))
    {
        // error...
    }
    for (int i = 0; i < character.getTotalHealth(); i++)
    {
        sf::Sprite h;
        h.setTexture(t);
        h.setPosition(0 + i * 64, 0);
        h.setScale(0.5, 0.5);
        health[i] = h;
    }
}

/**
 * @brief Draws the game screen with character, enemies, room bullets, and pickups.
 * @param window - Reference to the SFML window
 * @author Lorne Crewson
 */
int ViewModel::draw(sf::RenderWindow &window)

{
    int movespeed = 6;

    //background texture
    sf::Texture texture;
    if (!texture.loadFromFile(rooms[roomNumber]))
    {
        // error...
    }
    texture.setSmooth(true);

    //make background sprite with texture
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Font font;

    if (!font.loadFromFile("Arial.ttf"))
    {
        // error...
    }

    std::ostringstream ssScore;
    ssScore << "Score: " << score;
    sf::Text scoretext;
    scoretext.setFont(font);
    scoretext.setFillColor(sf::Color::Green);
    scoretext.setStyle(sf::Text::Bold);
    scoretext.setPosition(650, 10);
    scoretext.setString(ssScore.str());

    sf::Texture text;
    if (!text.loadFromFile("playerdamage.png"))
    {
        // error...
    }
    sf::Sprite damage;
    damage.setTexture(text);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        if (player.gety() < 80)
            player.playermove(sf::Vector2f(0, movespeed));
        player.playermove(sf::Vector2f(0, -movespeed));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        if (player.getx() < 100)
            player.playermove(sf::Vector2f(movespeed, 0));
        player.playermove(sf::Vector2f(-movespeed, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        if (player.gety() + player.getHeight() > 520)
            player.playermove(sf::Vector2f(0, -movespeed));
        player.playermove(sf::Vector2f(0, movespeed));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        if (player.getx() + player.getWidth() > 700)
            player.playermove(sf::Vector2f(-movespeed, 0));
        player.playermove(sf::Vector2f(movespeed, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        if (bulletFrame == 0)
        {
            Bullet b = Bullet();
            b.setDirection(0);
            b.setEmpty(false);
            b.setSpeed(bulletSpeed);
            b.setPosition(player.getx(), player.gety());
            if (bulletCount > bulletNumber - 1)
            {
                bulletCount = 0;
            }
            bullets[bulletCount] = b;
            bulletCount++;
            bulletFrame++;
            b.move();
        }
        else
        {
            if (bulletFrame > bulletFrameLimit)
            {
                bulletFrame = 0;
            }
            else
            {
                bulletFrame++;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        if (bulletFrame == 0)
        {
            Bullet b = Bullet();
            b.setDirection(1);
            b.setEmpty(false);
            b.setSpeed(bulletSpeed);
            b.setPosition(player.getx(), player.gety());
            if (bulletCount > bulletNumber - 1)
            {
                bulletCount = 0;
            }
            bullets[bulletCount] = b;
            bulletCount++;
            bulletFrame++;
            b.move();
        }
        else
        {
            if (bulletFrame > bulletFrameLimit)
            {
                bulletFrame = 0;
            }
            else
            {
                bulletFrame++;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        if (bulletFrame == 0)
        {
            Bullet b = Bullet();
            b.setDirection(2);
            b.setEmpty(false);
            b.setSpeed(bulletSpeed);
            b.setPosition(player.getx(), player.gety());
            if (bulletCount > bulletNumber - 1)
            {
                bulletCount = 0;
            }
            bullets[bulletCount] = b;
            bulletCount++;
            bulletFrame++;
            b.move();
        }
        else
        {
            if (bulletFrame > bulletFrameLimit)
            {
                bulletFrame = 0;
            }
            else
            {
                bulletFrame++;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        if (bulletFrame == 0)
        {
            Bullet b = Bullet();
            b.setDirection(3);
            b.setEmpty(false);
            b.setSpeed(bulletSpeed);
            b.setPosition(player.getx(), player.gety());
            if (bulletCount > bulletNumber - 1)
            {
                bulletCount = 0;
            }
            bullets[bulletCount] = b;
            bulletCount++;
            bulletFrame++;
            b.move();
        }
        else
        {
            if (bulletFrame > bulletFrameLimit)
            {
                bulletFrame = 0;
            }
            else
            {
                bulletFrame++;
            }
        }
    }
    // Every loop the enemy will update its behaviour to simulate following the player

    window.draw(sprite);

    if (map_info[roomNumber].getNumEnemies() == 0)
    {
        if (pUps[roomNumber].getEmpty() == false)
        {
            sf::Texture healthTexture;
            healthTexture.loadFromFile(pUps[roomNumber].types[pUps[roomNumber].type]);
            pUps[roomNumber].powerImg.setTexture(healthTexture);
            pUps[roomNumber].powerImg.setPosition(250, 250);
            window.draw(pUps[roomNumber].powerImg);

            if (pUps[roomNumber].pickup(player.getWidth(), player.getHeight(), player.getx(), player.gety()))
            {
                if (pUps[roomNumber].type == 1)
                {
                    if (character.getHealth() < 3)
                    {
                        character.setHealth(character.getHealth() + 1);
                    }
                }
                else if (pUps[roomNumber].type == 2)
                {
                    character.setSpeed(character.getSpeed() + 10);
                }
                else
                {
                    character.setStrength(character.getStrength() + 10);
                }

                pUps[roomNumber].setEmpty(true);
            }
        }
    }

    player.draw(window);
    if (map.getBossRoom() == roomNumber)
    {
        if (boss.getEmpty() == false)
        {
            boss.follow(player.getx(), player.gety());
            boss.draw(window);
            if (boss.attack(player.getWidth(), player.getHeight(), player.getx(), player.gety()))
            {
                if (damageTimer == 0)
                {

                    damagePosition[0] = player.getx();
                    damagePosition[1] = player.gety();
                    damage.setPosition(damagePosition[0], damagePosition[1]);
                    window.draw(damage);

                    character.setHealth(character.getHealth() - 1);
                    if (character.getHealth() == 0)
                    {
                        return 0;
                    }
                    damageTimer++;
                }
                else
                {
                    damageTimer++;
                    if (damageTimer > 10)
                    {
                        damageTimer = 0;
                    }
                }
            }
        }
    }

    if (enemies[roomNumber].getEmpty() == false)
    {
        enemies[roomNumber].follow(player.getx(), player.gety());
        enemies[roomNumber].draw(window);
        if (enemies[roomNumber].attack(player.getWidth(), player.getHeight(), player.getx(), player.gety()))
        {
            if (damageTimer == 0)
            {

                damagePosition[0] = player.getx();
                damagePosition[1] = player.gety();
                damage.setPosition(damagePosition[0], damagePosition[1]);
                window.draw(damage);

                character.setHealth(character.getHealth() - 1);
                if (character.getHealth() == 0)
                {
                    return 0;
                }
                damageTimer++;
            }
            else
            {
                damageTimer++;
                if (damageTimer > 10)
                {
                    damageTimer = 0;
                }
            }
        }
    }

    if (damageTimer > 0 && damageTimer < 6)
    {
        damage.setPosition(damagePosition[0], damagePosition[1]);
        window.draw(damage);
        damageTimer++;
    }
    for (int i = 0; i < bulletNumber; i++)
    {
        if (bullets[i].getEmpty() == false)
        {
            bullets[i].move();
            bullets[i].draw(window);
            if (enemies[roomNumber].getEmpty() == false)
            {
                if (enemies[roomNumber].attack(bullets[i].getWidth() * 2, bullets[i].getHeight() * 2, bullets[i].getx(), bullets[i].gety()))
                {
                    enemies[roomNumber].setEmpty(true);
                    score++;
                    ssScore.str("");
                    ssScore << "Score: " << score;
                    scoretext.setString(ssScore.str());
                    map_info[roomNumber].lowerEnemyNumber();
                    if (map_info[roomNumber].getNumEnemies() == 0)
                    {
                        map_info[roomNumber].setLockStatus(false);
                    }
                }
            }

            if (map.getBossRoom() == roomNumber)
            {
                if (boss.getEmpty() == false)
                {
                    if (boss.attack(bullets[i].getWidth() * 2, bullets[i].getHeight() * 2, bullets[i].getx(), bullets[i].gety()))
                    {
                        bossHealth--;
                    }
                    if (bossHealth == 0)
                    {
                        boss.setEmpty(true);
                        score += 100;
                        ssScore.str("");
                        ssScore << "Score: " << score;
                        scoretext.setString(ssScore.str());
                        return 1;
                    }
                }
            }
            if (bullets[i].inBounds() == false)
            {
                bullets[i].setEmpty(true);
            }
        }
    }
    for (int i = 0; i < character.getHealth(); i++)
    {
        sf::Texture t;
        if (!t.loadFromFile("health128.png"))
        {
            // error...
        }
        health[i].setTexture(t);
        window.draw(health[i]);
    }
    window.draw(scoretext);
    bool readyForBoss = true;
    for (int i = 0; i < 9; i++)
    {
        readyForBoss = (enemies[i].getEmpty() && readyForBoss);
    }
    if (map_info[roomNumber].getLockStatus() == false)
    {
        if (player.gety() > 230 && player.gety() < 360 && player.getx() < 140)
        {
            //printf("left door hit");
            if (roomNumber == 1 || roomNumber == 2 || roomNumber == 4 || roomNumber == 5 || roomNumber == 7 || roomNumber == 8)
            {
                int newRoomNumber = roomNumber - 1;
                if (newRoomNumber == map.getBossRoom())
                {
                    if (readyForBoss)
                    {
                        roomNumber = newRoomNumber;
                        player.setPosition(550, 275);
                    }
                    else
                    {
                        //text
                        sf::Font font;

                        if (!font.loadFromFile("Arial.ttf"))
                        {
                            // error...
                        }

                        sf::Text bossLock("Must defeat all enemies before entering!", font, 40);
                        bossLock.setFillColor(sf::Color::Red);
                        bossLock.setStyle(sf::Text::Bold);
                        bossLock.setPosition(75, 350);
                        window.draw(bossLock);
                        warningTimer = 0;
                    }
                }
                else
                {
                    roomNumber = newRoomNumber;
                    player.setPosition(550, 275);
                }
            }
        }
        if (player.getx() > 340 && player.getx() < 460 && player.gety() + player.getHeight() > 500)
        {
            //printf("bottom door hit");
            if (roomNumber == 0 || roomNumber == 1 || roomNumber == 2 || roomNumber == 3 || roomNumber == 4 || roomNumber == 5)
            {

                int newRoomNumber = roomNumber + 3;
                if (newRoomNumber == map.getBossRoom())
                {
                    if (readyForBoss)
                    {
                        roomNumber = newRoomNumber;
                        player.setPosition(375, 150);
                    }
                    else
                    {
                        //text
                        sf::Font font;

                        if (!font.loadFromFile("Arial.ttf"))
                        {
                            // error...
                        }

                        sf::Text bossLock("Must defeat all enemies before entering!", font, 40);
                        bossLock.setFillColor(sf::Color::Red);
                        bossLock.setStyle(sf::Text::Bold);
                        bossLock.setPosition(25, 350);
                        warningTimer = 0;
                        window.draw(bossLock);
                    }
                }
                else
                {
                    roomNumber = newRoomNumber;
                    player.setPosition(375, 150);
                }
            }
        }
        if (player.gety() > 230 && player.gety() < 360 && player.getx() + player.getWidth() > 690)
        {
            //printf("right door hit");
            if (roomNumber == 0 || roomNumber == 1 || roomNumber == 3 || roomNumber == 4 || roomNumber == 6 || roomNumber == 7)
            {

                int newRoomNumber = roomNumber + 1;
                if (newRoomNumber == map.getBossRoom())
                {
                    if (readyForBoss)
                    {
                        roomNumber = newRoomNumber;
                        player.setPosition(150, 275);
                    }
                    else
                    {
                        //text
                        sf::Font font;

                        if (!font.loadFromFile("Arial.ttf"))
                        {
                            // error...
                        }

                        sf::Text bossLock("Must defeat all enemies before entering!", font, 40);
                        bossLock.setFillColor(sf::Color::Red);
                        bossLock.setStyle(sf::Text::Bold);
                        bossLock.setPosition(25, 350);
                        warningTimer = 0;
                        window.draw(bossLock);
                    }
                }
                else
                {
                    roomNumber = newRoomNumber;
                    player.setPosition(150, 275);
                }
            }
        }
        if (player.getx() > 340 && player.getx() < 460 && player.gety() < 110)
        {
            //printf("top door hit");
            if (roomNumber == 3 || roomNumber == 4 || roomNumber == 5 || roomNumber == 6 || roomNumber == 7 || roomNumber == 8)
            {

                int newRoomNumber = roomNumber - 3;
                if (newRoomNumber == map.getBossRoom())
                {
                    if (readyForBoss)
                    {
                        roomNumber = newRoomNumber;
                        player.setPosition(375, 350);
                    }
                    else
                    {
                        //text
                        sf::Font font;

                        if (!font.loadFromFile("Arial.ttf"))
                        {
                            // error...
                        }

                        sf::Text bossLock("Must defeat all enemies before entering!", font, 40);
                        bossLock.setFillColor(sf::Color::Red);
                        bossLock.setStyle(sf::Text::Bold);
                        bossLock.setPosition(25, 350);
                        warningTimer = 0;
                        window.draw(bossLock);
                    }
                }
                else
                {
                    roomNumber = newRoomNumber;
                    player.setPosition(375, 350);
                }
            }
        }
    }
    if (warningTimer < 10)
    {
        sf::Font font;

        if (!font.loadFromFile("Arial.ttf"))
        {
            // error...
        }

        sf::Text bossLock("Must defeat all enemies before entering!", font, 40);
        bossLock.setFillColor(sf::Color::Red);
        bossLock.setStyle(sf::Text::Bold);
        bossLock.setPosition(25, 350);
        warningTimer++;
        window.draw(bossLock);
    }
    return -1;
}
