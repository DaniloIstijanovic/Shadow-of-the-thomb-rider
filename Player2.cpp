#include <SFML/Graphics.hpp>
#include <iostream>
#include "hpps/Entity.h"
#include "hpps/Player.h"

Player2::Player2::(const std::string& textureFile, float i_x, float i_y, float i_w, float i_h) {
	m_texture.loadFromFile(textureFile);
	m_vertices.setPrimitiveType(sf::Quad);
	m_vertices.resize(i_w * i_h * 4);

	m_vertices[0].position = sf::Vector2f(i_x, i_y);
	m_vertices[1].position = sf::Vector2f(i_x + i_w, i_y);
	m_vertices[2].position = sf::Vector2f(i_x + i_w, i_y + i_h);
	m_vertices[3].position = sf::Vector2f(i_x, i_y + i_h);

	m_vertices[0].texCoords = sf::Vector(0, 0);
	m_vertices[1].texCoords = sf::Vector(i_w, 0);
	m_vertices[2].texCoords = sf::Vector(i_w, i_h);
	m_vertices[3].texCoords = sf::Vector(0, i_h);

	m_transform.scale(3.0f, 3.0f, i_x, i_y);
	m_x = 0.0f;
	m_y = 0.0f;

}
