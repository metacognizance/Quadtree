#include <SFML\Graphics\RenderWindow.hpp>

#include "Main.h"

int main(){
	Main main = Main();

	return 0;
}

Main::Main() : 
	m_running(true),
	m_active(true),
	m_window(sf::RenderWindow(sf::VideoMode(640, 640), "", sf::Style::Close)),
	m_delay(0.f)
{
	run();
}

Main::~Main(){

}

void Main::run(){
	initialize();

	sf::Clock dt;
	sf::Time lag;
	sf::Time updateTime = sf::seconds(1.f/60.f);

	while (m_running)
	{
		lag += dt.getElapsedTime();
		dt.restart();

		handleEvents();
		render();
		while (lag >= updateTime && m_active)
		{
			update(updateTime);
			lag -= updateTime;
		}
	}
}

void Main::initialize(){
	m_quadtree = Quadtree();
}

void Main::handleEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
		{
			m_window.close();
			m_running = false;
		}else if (event.type == sf::Event::GainedFocus){
			m_active = true;
		} else if (event.type == sf::Event::LostFocus) {
			m_active = false;
		}
	}
}

void Main::update(const sf::Time & p_deltaTime){
	m_delay -= p_deltaTime.asSeconds();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_delay <= 0.f)
	{
		Object object = Object(sf::Rect<float>(sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y, 2, 2));
		m_quadtree.m_root.insert(object);
		m_delay = 0.1f;
	}
}

void Main::render(){
	m_window.clear(sf::Color::Black);
	m_window.draw(m_quadtree);
	m_window.display();
}