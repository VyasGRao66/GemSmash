#pragma once
#include <SFML/Graphics.hpp>
class GreenGem
{
private:
    sf::Vector2f m_Position;
    sf::Texture m_texture;
    sf::Sprite m_sprite;

public:
    GreenGem(float startX, float startY);

    sf::FloatRect getPosition();

    sf::Sprite getShape();

    sf::FloatRect setPos(float posX, float posY);

};

