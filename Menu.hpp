#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Position.hpp"

class UI_Element;

using namespace sf;
using namespace std;

class Menu {
public:
	Menu(RenderWindow& _w) : window(_w), color(Color::White) {
		bg = RectangleShape(Vector2f(window.getView().getSize().x, window.getView().getSize().y));

		bg.setFillColor(color);

		bg.setOrigin(bg.getLocalBounds().height / 2, bg.getLocalBounds().width / 2);
		bg.setPosition(window.getView().getCenter().x, window.getView().getCenter().y);
	}

	Menu(RenderWindow& w, Color c) : window(w), color(c) {
		bg = RectangleShape(Vector2f(window.getView().getSize().x, window.getView().getSize().y));

		bg.setFillColor(color);

		bg.setOrigin(bg.getLocalBounds().height / 2, bg.getLocalBounds().width / 2);
		bg.setPosition(window.getView().getCenter().x, window.getView().getCenter().y);
	}

	void setBackground(sf::Color color);

	Color getBgColor() {
		return color;
	}

	sf::RenderWindow& getWindow() {
		return window;
	}

	void addElement(UI_Element& e);

	void visible(bool v) {
		_visible = v;
	}

	bool isVisible() {
		return _visible;
	}

	void draw();
	void input(sf::Event event);
private:
	RenderWindow& window;

	bool _visible = true;

	vector<UI_Element> elements;

	Color color;
	RectangleShape bg;
};