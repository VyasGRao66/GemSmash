#include "YellowGem.h"
YellowGem::YellowGem(float startX, float startY) {

	m_Position.x = startX;
	m_Position.y = startY;



	m_texture.loadFromFile("SRC/imgs/YellowGem.png");
	m_sprite.setTexture(m_texture);

	m_sprite.setPosition(m_Position);



}

sf::FloatRect YellowGem::getPosition() {

	return m_sprite.getGlobalBounds();
}

sf::Sprite YellowGem::getShape() {

	return m_sprite;
}

sf::FloatRect YellowGem::setPos(float posX, float posY) {
	m_Position.x = posX;
	m_Position.y = posY;
	m_sprite.setPosition(m_Position);	
	return m_sprite.getGlobalBounds();

}