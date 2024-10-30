#include <iostream>
#include <SFML/Graphics.hpp>
#include "BlueGem.h"
#include "GreenGem.h"
#include "RedGem.h"
#include "YellowGem.h"
#include <vector>
#include <SFML/Window/Mouse.hpp>
#include <sstream>

struct Gem {
    std::string colour;
    int x;
    int y;
};  

void horizontalThree();
void verticalThree();
void bringDown();
void fillGem();
void clickPress();
void clickRelease();
bool checkRow(Gem clickOne, Gem clickTwo, int loc1, int loc2);


int score = 0;
bool click = false;
std::vector<Gem> gems;

sf::Vector2f clickStart;
sf::Vector2f clickEnd;


sf::VideoMode VM(800, 800);
sf::RenderWindow window(VM, "Gem Smash");

int main()
{
    
    srand(time(NULL));
    int gemPicker;

    BlueGem blueGem(0, 0);
    GreenGem greenGem(0, 0);
    RedGem redGem(0, 0);
    YellowGem yellowGem(0, 0);

    sf::RectangleShape boarder1;
    boarder1.setSize(sf::Vector2f(100, 800));
    boarder1.setFillColor(sf::Color::Blue);

    sf::RectangleShape boarder2;
    boarder2.setSize(sf::Vector2f(100, 800));
    boarder2.setFillColor(sf::Color::Blue);
    boarder2.setPosition(700, 0);


    sf::Font font;
    font.loadFromFile("SRC/Fonts/Bangers-Regular.ttf");
    sf::Text currentScore;
    currentScore.setFont(font);
    currentScore.setPosition(10, 10);
    currentScore.setCharacterSize(20);
    currentScore.setFillColor(sf::Color::Green);
    std::stringstream ss;


    ss << "Score: " << score;
    currentScore.setString(ss.str());

    for (int h = 0; h < 8; h++) {
        for (int i = 1; i <= 6; i++) {
            
            gemPicker = (rand() % 4);
            Gem gem;
            gem.x = (100 * i);
            gem.y = h * 100;
            
            if (gemPicker == 0) {
                gem.colour = "blue";
            }

            else if (gemPicker == 1) {
                gem.colour = "green";
            }

            else if (gemPicker == 2) {
                gem.colour = "red";
            }

            else if (gemPicker == 3) {
                gem.colour = "yellow";

            }

            gems.push_back(gem);
        }
    }

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
        }
        
        

        horizontalThree();
        verticalThree();

        clickPress();
        clickRelease();
        

        bringDown();
        fillGem();

        window.clear();

        for (int i = 0; i < 48; i++) {
            Gem gem;
            gem = gems[i];
            
            if (gem.colour == "blue") {
                blueGem.setPos(gem.x, gem.y);
                window.draw(blueGem.getShape());

            }
            else if (gem.colour == "green") {
                greenGem.setPos(gem.x, gem.y);
                window.draw(greenGem.getShape());

            }
            else if (gem.colour == "red") {
                redGem.setPos(gem.x, gem.y);
                window.draw(redGem.getShape());

            }
            else if (gem.colour == "yellow") {
                yellowGem.setPos(gem.x, gem.y);
                window.draw(yellowGem.getShape());

            }
        }

        ss.str("");
        ss << "Score: " << score;
        currentScore.setString(ss.str());


        window.draw(boarder1);
        window.draw(boarder2);
        window.draw(currentScore);


        

        window.display();


    }
}

void horizontalThree() {
    int amt = 0;
    for (int i = 0; i < 8; i = i++) {
        for (int h = 0; h < 4; h++) {
            Gem gem1, gem2, gem3;
            gem1 = gems[amt + h];
            gem2 = gems[amt + h + 1];
            gem3 = gems[amt + h + 2];
            if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {

                score++;
                gem1.colour = "";
                gem2.colour = "";
                gem3.colour = "";
                gems[amt + h] = gem1;
                gems[amt + h + 1] = gem2;
                gems[amt + h + 2] = gem3;
            }
        }
        amt += 6;
    }
    amt = 0;   
}

void verticalThree() {
    for (int i = 0; i < 6; i++) {
        for (int h = 0; h <= 30; h = h + 6) {
            Gem gem1, gem2, gem3;
            gem1 = gems[i + h];
            gem2 = gems[i + h + 6];
            gem3 = gems[i + h + 12];
            if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
                score++;
                gem1.colour = "";
                gem2.colour = "";
                gem3.colour = "";
                gems[i + h] = gem1;
                gems[i + h + 6] = gem2;
                gems[i + h + 12] = gem3;
            }
        }
    }
}

void bringDown() {
    for (int i = 0; i < 6; i++) {
        for (int h = 42; h >= 6; h -= 6) {
            Gem gem1, gem2;
            gem1 = gems[i + h];
            gem2 = gems[i + h - 6];

            if (gem1.colour == "") {
                gem1.colour = gem2.colour;

                gem2.colour = "";

                gems[i + h] = gem1;
                gems[i + h - 6] = gem2;
            }

        }
    }
}

void fillGem() {
    srand(time(NULL));
    int gemPicker;
    for (int i = 0; i < 48 ; i++) {
        Gem gem;
        gemPicker = (rand() % 4);
        gem = gems[i];
        if (gem.colour == "") {
            if (gemPicker == 0) {
                gem.colour = "blue";
            }

            else if (gemPicker == 1) {
                gem.colour = "green";
            }

            else if (gemPicker == 2) {
                gem.colour = "red";
            }

            else if (gemPicker == 3) {
                gem.colour = "yellow";

            }
            gems[i] = gem;
        }
    }
}

void clickPress() {
    if (click == false && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        click = true;
        clickStart.x = sf::Mouse::getPosition(window).x;
        clickStart.y = sf::Mouse::getPosition(window).y;

        int x = (int)(clickStart.x / 100) * 100;
        int y = (int)(clickStart.y / 100) * 100;
        clickStart.x = x;
        clickStart.y = y;

    }
}

void clickRelease() {
    if (click && sf::Mouse::isButtonPressed(sf::Mouse::Left) == false) {

        clickEnd.x = sf::Mouse::getPosition(window).x;
        clickEnd.y = sf::Mouse::getPosition(window).y;

        int x = (int)(clickEnd.x / 100) * 100;
        int y = (int)(clickEnd.y / 100) * 100;

        clickEnd.x = x;
        clickEnd.y = y;



        bool endLoop = false;

        for (int i = 0; i < 48; i++) {
            for (int h = 0; h < 48; h++) {
                Gem gem1;
                Gem gem2;

                gem1 = gems[i];
                gem2 = gems[h];



                if (gem1.x == clickStart.x && gem1.y == clickStart.y && gem2.x == clickEnd.x && gem2.y == clickEnd.y) {
                    if (i + 1 == h || i - 1 == h || i + 6 == h || i - 6 == h) {
                        
                       

                        gem2.x = clickStart.x;
                        gem2.y = clickStart.y;

                        gem1.x = clickEnd.x;
                        gem1.y = clickEnd.y;

                        gems[i] = gem2;
                        gems[h] = gem1;
                        if (checkRow(gem1, gem2, i, h) == false) {

                            gem1.x = clickStart.x;
                            gem1.y = clickStart.y;

                            gem2.x = clickEnd.x;
                            gem2.y = clickEnd.y;

                            gems[i] = gem1;
                            gems[h] = gem2;

                        }


                        endLoop = true;

                        clickStart.x = 0;
                        clickStart.y = 0;
                        clickEnd.x = 0;
                        clickEnd.y = 0;

                        break;
                    }
                    
                }
            }
            if (endLoop) {
                break;
            }
        }

        click = false;

    }
}

bool checkRow(Gem clickOne, Gem clickTwo, int loc1, int loc2) {
    Gem gem1, gem2, gem3;
    
    if (loc1 < 46 && loc2 < 46) {
        gem1 = clickOne;
        gem2 = gems[loc2 + 1];
        gem3 = gems[loc2 + 2];
        if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
            return true;
        }

        gem1 = clickTwo;
        gem2 = gems[loc1 + 1];
        gem3 = gems[loc1 + 2];
        if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
            return true;
        }
    }

    if (loc1 > 2 && loc2 > 2) {
        gem1 = clickTwo;
        gem2 = gems[loc1 - 1];
        gem3 = gems[loc1 - 2];
        if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
            return true;
        }

        gem1 = clickOne;
        gem2 = gems[loc2 - 1];
        gem3 = gems[loc2 - 2];
        if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
            return true;
        }
    }
    
    if (loc1 < 36 && loc2 < 36) {
        gem1 = clickTwo;
        gem2 = gems[loc1 + 6];
        gem3 = gems[loc1 + 12];
        if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
            return true;
        }

        gem1 = clickOne;
        gem2 = gems[loc2 + 6];
        gem3 = gems[loc2 + 12];
        if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
            return true;
        }
    }

    if (loc1 > 11 && loc2 > 11) {
        gem1 = clickTwo;
        gem2 = gems[loc1 - 6];
        gem3 = gems[loc1 - 12];
        if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
            return true;
        }

        gem1 = clickOne;
        gem2 = gems[loc2 - 6];
        gem3 = gems[loc2 - 12];
        if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
            return true;
        }
    }

    if (loc1 != 0 && loc1 != 47 && loc2 != 0 && loc2 != 47) {
        gem1 = clickTwo;
        gem2 = gems[loc1 + 1];
        gem3 = gems[loc1 - 1];
        if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
            return true;
        }

        gem1 = clickOne;
        gem2 = gems[loc2 + 1];
        gem3 = gems[loc2 - 1];
        if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
            return true;
        }
    }

    if (loc1 < 42 && loc1 > 5 && loc2 < 42 && loc2 > 5) {
        gem1 = clickTwo;
        gem2 = gems[loc1 + 6];
        gem3 = gems[loc1 - 6];
        if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
            return true;
        }

        gem1 = clickOne;
        gem2 = gems[loc2 + 6];
        gem3 = gems[loc2 - 6];
        if (gem1.colour == gem2.colour && gem1.colour == gem3.colour) {
            return true;
        }

    }

    return false;

    
}

