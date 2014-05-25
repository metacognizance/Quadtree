#include "Object.h"

Object::Object()
{

}

Object::Object(const sf::Rect<float> & p_bounds) : 
	m_bounds(p_bounds)
{
	setPosition(sf::Vector2<float>(p_bounds.left, p_bounds.top));
}

Object::~Object(){

}

sf::Rect<float> Object::getBounds() const{
	return m_bounds;
}

void Object::draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const{
	sf::RectangleShape rectShape = sf::RectangleShape(sf::Vector2<float>(m_bounds.width, m_bounds.height));
	rectShape.setPosition(sf::Vector2<float>(m_bounds.left, m_bounds.top));
	rectShape.setFillColor(sf::Color::Magenta);
	p_target.draw(rectShape, p_states);
}