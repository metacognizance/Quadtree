#pragma once
#include <SFML\Graphics\Rect.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <string>

struct Object : public sf::Drawable, public sf::Transformable{
	Object();
	Object(const sf::Rect<float> & p_bounds);
	~Object();

	sf::Rect<float> getBounds() const;

private:
	sf::Rect<float> m_bounds;

	void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const;
};