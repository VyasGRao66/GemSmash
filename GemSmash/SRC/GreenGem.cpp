#include "GreenGem.h"

GreenGem::GreenGem(float startX, float startY) {
	m_Position.x = startX;
	m_Position.y = startY;



	m_texture.loadFromFile("SRC/imgs/GreenGem.png");
	m_sprite.setTexture(m_texture);

	m_sprite.setPosition(m_Position);

}

sf::FloatRect GreenGem::getPosition() {

	return m_sprite.getGlobalBounds();
}

sf::Sprite GreenGem::getShape() {

	return m_sprite;
}

sf::FloatRect GreenGem::setPos(float posX, float posY) {
	m_Position.x = posX;
	m_Position.y = posY;
	m_sprite.setPosition(m_Position);
	return m_sprite.getGlobalBounds();

}