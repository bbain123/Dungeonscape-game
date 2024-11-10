#include <SFML/Graphics.hpp>
#include <string>

class Boss
{
    private:
        std::string types[1][2]= {{"vampire128.png","vampire128_move.png"}};
		sf::Texture texture;
        sf::Sprite boss;
        int width = 128;
        int height = 128;
        bool animate = false;
        int frameCount = 0;
		int movespeed;
        bool empty = false;
        int bossType = 0;

        public:
		
		Boss() {
            /*
			enemy.setSize(sf::Vector2f(50,50));
			enemy.setFillColor(sf::Color::Red);
            */
			movespeed = 2;
            if (!texture.loadFromFile(types[bossType][0]))
                {
                    // error...
                }
            boss.setTexture(texture);
            boss.setTextureRect(sf::IntRect(0, 0, width, height));
            boss.setPosition(0,0);
		}

		/*
		sf::RectangleShape getShape() {
			return enemy;
		}*/
		
		void setpos(sf::Vector2f newPosition) {
			boss.setPosition(newPosition);
		}
		void setEmpty(bool val){
            this->empty = val;
        }
        bool getEmpty(){
            return this->empty;
        }
        void setType(int type){
            this->bossType = type;
        }
		void follow(int playerx, int playery) {
			int movex = movespeed, movey = movespeed;
			
			if (playerx < boss.getPosition().x) movex = movespeed * -1;
			if (playery < boss.getPosition().y) movey = movespeed * -1;
			
			boss.move(movex, movey);
            if(animate){
                if(frameCount){
                    frameCount++;
                    if(frameCount>5){
                        frameCount=0;
                    }
                }
                else{
                    if (!texture.loadFromFile(types[bossType][1]))
                    {
                        // error...
                    }
                    boss.setTexture(texture);
                    animate = false;
                    frameCount++;
                }
                
            }
            else{
                if(frameCount){
                    frameCount++;
                    if(frameCount>5){
                        frameCount=0;
                    }
                }
                else{
                    if (!texture.loadFromFile(types[bossType][0]))
                    {
                        // error...
                    }
                    boss.setTexture(texture);
                    animate = true;
                    frameCount++;
                }
            }
            
		}
		
        /*
		void collision(Bullet bullet) {
			if (bullet.getRight() > enemy.getPosition().x && bullet.getTop() < enemy.getPosition().y + enemy.getSize().y && bullet.getBottom() > enemy.getPosition().y) {
				enemy.setPosition(sf::Vector2f(123124124, 12312321));
			}
		}*/
		bool attack(int w, int h, int x, int y){
            bool hurt = false;
            
            
            int posPlayerWidthSize = x+(w/2);
            int negPlayerWidthSize = x-(w/2);
            int posPlayerHeightSize = y+(h/2);
            int negPlayerHeightSize = y-(h/2);
            
            //printf("%d %d",negEnemyWidthSize,posPlayerWidthSize);
            
            if(negPlayerWidthSize < this->getx() && this->getx() < posPlayerWidthSize && negPlayerHeightSize< this->gety() && this->gety()< posPlayerHeightSize){
                hurt = true;
            }

            return hurt;
        }
		int getWidth() {
			return this->width;
		}
		
		int getHeight() {
			return this->height;
		}
		
		int getx() {
			return boss.getPosition().x;
		}
		
		int gety() {
			return boss.getPosition().y;
		}
		
		void draw(sf::RenderWindow& window) {
			window.draw(boss);
		}
};