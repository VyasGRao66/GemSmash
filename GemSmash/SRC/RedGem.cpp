#include "RedGem.h"

RedGem::RedGem(float startX, float startY) {
	m_Position.x = startX;
	m_Position.y = startY;



	m_texture.loadFromFile("SRC/imgs/RedGem.png");
	m_sprite.setTexture(m_texture);

	m_sprite.setPosition(m_Position);

}

sf::FloatRect RedGem::getPosition() {

	return m_sprite.getGlobalBounds();
}

sf::Sprite RedGem::getShape() {

	return m_sprite;
}

sf::FloatRect RedGem::setPos(float posX, float posY) {
	m_Position.x = posX;
	m_Position.y = posY;
	m_sprite.setPosition(m_Position);
	return m_sprite.getGlobalBounds();

}

