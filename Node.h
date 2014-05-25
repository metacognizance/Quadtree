#pragma once
#include <vector>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\RectangleShape.hpp>

#include "Object.h"

struct Node : public sf::Drawable, public sf::Transformable{
	Node();
	Node(const unsigned short & p_divisions, const unsigned short & p_maxDivisions, const unsigned short & p_maxObjects, const sf::Rect<int> p_bounds);
	~Node();

	Node* ptr_children[4];

	void insert(const Object & p_object);

	sf::Rect<int> getBounds() const;

	void getObjects(std::vector<Object> & p_objects, const Object & p_object);

	void clean();

	void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const;

private:
	unsigned short m_divisions;

	unsigned short m_maxDivisions;
	unsigned short m_maxObjects;

	sf::Rect<int> m_bounds;

	std::vector<Object> m_objects;

	void split();
	
	int getIndex(const Object & p_object) const;
};