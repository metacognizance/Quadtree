#include "Quadtree.h"
#include <iostream>

Quadtree::Quadtree(){
	m_root = Node(0, m_maxDivisions, m_maxObjects, sf::Rect<int>(0, 0, 640, 640));
}

Quadtree::~Quadtree(){
	clean();
}

void Quadtree::clean(){
	m_root.clean();
}

void Quadtree::draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const{
	m_root.draw(p_target, p_states);
}