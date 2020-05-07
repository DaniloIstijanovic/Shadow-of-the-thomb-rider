#include <SFML/Graphics.hpp>
#include "hpps/Entity.h"

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform = m_transform;

	states.texture = &m_texture;
	target.draw(m_vertices, states);



}
