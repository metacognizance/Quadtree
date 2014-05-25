#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Window\Event.hpp>

#include "Quadtree.h"

class Main{
public:
	Main();
	~Main();

private:
	void run();
	void initialize();
	void handleEvents();
	void update(const sf::Time & p_deltaTime);
	void render();

	sf::RenderWindow m_window;

	Quadtree m_quadtree;

	bool m_running, m_active;

	float m_delay;
};