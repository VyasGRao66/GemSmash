#pragma once
#include <SFML/Graphics.hpp>
class YellowGem
{
private:

    sf::Vector2f m_Position;
    sf::Texture m_texture;
    sf::Sprite m_sprite;



public:
    YellowGem(float startX, float startY);

    sf::FloatRect getPosition();

    sf::Sprite getShape();

    sf::FloatRect setPos(float posX, float posY);
};

