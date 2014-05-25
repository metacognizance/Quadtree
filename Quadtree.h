#pragma once
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include "Node.h"

class Quadtree : public sf::Drawable{
public:
	Quadtree();
	~Quadtree();

	Node m_root;

	void clean();

private:
	///<summary>Represents the amount of objects that a node can hold before it needs to split into four child-nodes.</summary>
	static const unsigned short m_maxObjects = 3;

	///<summary>Represents the maximum amount of divisions. 0 is the root node.</summary>
	static const unsigned short m_maxDivisions = 10;

	void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const;
};