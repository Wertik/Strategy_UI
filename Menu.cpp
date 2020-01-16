#include <SFML/Graphics.hpp>
#include <iostream>

#include "Menu.hpp"
#include "UI_Element.hpp"

using namespace sf;

void Menu::draw() {
	if (_visible) {
		window.draw(bg);

		for (UI_Element& e : elements) {

			switch (e.m_visual.m_type) {
			case CIRC:
				window.draw(e.m_visual.c_shape);
				break;
			case RECT:
				window.draw(e.m_visual.r_shape);
			}
		}
	}
}

void Menu::input(sf::Event e) {
	if (e.type == Event::MouseButtonPressed) {
		Position mouse_pos = Position(window.mapPixelToCoords(Mouse::getPosition(window), window.getView()));

		for (UI_Element& e : elements) {
			if (e.clickable)
				switch (e.m_visual.m_type) {
				case CIRC:
					if (e.m_visual.c_shape.getGlobalBounds().contains(mouse_pos.toVector())) {
						e.clickPtr(this, e);
					}
					break;
				case RECT:
					if (e.m_visual.r_shape.getGlobalBounds().contains(mouse_pos.toVector())) {
						e.clickPtr(this, e);
					}
				}
		}
	}
}

void Menu::addElement(UI_Element& e) {
	elements.push_back(e);
}

void Menu::setBackground(Color c) {
	bg.setFillColor(c);
	color = c;
}