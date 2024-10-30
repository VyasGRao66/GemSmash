#include "BlueGem.h"

BlueGem::BlueGem(float startX, float startY) {

	m_Position.x = startX;
	m_Position.y = startY;


	
	m_texture.loadFromFile("SRC/imgs/BlueGem.png");
	m_sprite.setTexture(m_texture);

	m_sprite.setPosition(m_Position);

	

}

sf::FloatRect BlueGem::getPosition() {

	return m_sprite.getGlobalBounds();
}

sf::Sprite BlueGem::getShape() {

	return m_sprite;
}


sf::FloatRect BlueGem::setPos(float posX, float posY) {
	m_Position.x = posX;
	m_Position.y = posY;
	m_sprite.setPosition(m_Position);
	return m_sprite.getGlobalBounds();


}