#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Position.hpp"

class Menu;

using namespace sf;
using namespace std;

// Class layout, seperate later on.

struct UI_Style {
	// Hold style parameters
	sf::Color color;
	sf::Vector2f m_size;
	float radius;

	// Text styling
	sf::Text m_text;
	sf::Font m_font;
};

enum ShapeType {
	NONE,
	RECT,
	CIRC
};

static string toString(ShapeType type) {
	switch (type) {
	default:
	case NONE:
		return "none";
	case RECT:
		return "rect";
	case CIRC:
		return "circ";
	}
}

struct UI_Visual {
	ShapeType m_type;
	RectangleShape r_shape;
	CircleShape c_shape;
};

class UI_Element {
public:
	UI_Element() : m_style({Color::White, Vector2f(10, 10), 10}) {
		m_visual = { NONE, RectangleShape(m_style.m_size), CircleShape(m_style.radius) };
		updateStyle();
	}

	UI_Element(UI_Style style) : m_style(style) {
		m_visual = { NONE, RectangleShape(m_style.m_size), CircleShape(m_style.radius) };

		updateStyle();
	}

	UI_Element(ShapeType type, UI_Style style, Position pos, void (*_clickPtr)(Menu*, UI_Element))
		: clickPtr(_clickPtr), m_style(style) {

		clickable = true;

		m_visual.m_type = type;
		
		if (m_visual.m_type == ShapeType::RECT) {
			m_visual.r_shape.setPosition(pos.x, pos.y);
		}
		else {
			m_visual.c_shape.setPosition(pos.x, pos.y);
		}

		updateStyle();
	}

	UI_Element(UI_Style style, Position pos, void (*_clickPtr)(Menu*, UI_Element))
		: clickPtr(_clickPtr), m_style(style) {

		clickable = true;

		if (style.radius == 0) {
			m_visual.m_type = ShapeType::RECT;
			m_visual.r_shape.setPosition(pos.x, pos.y);
		}
		else if (style.m_size == Vector2f(0, 0)) {
			m_visual.m_type = ShapeType::CIRC;
			m_visual.c_shape.setPosition(pos.x, pos.y);
		}
		else {
			m_visual.m_type = ShapeType::NONE;
		}		

		updateStyle();
	}

	UI_Element(UI_Style style, Position pos)
		: m_style(style) {

		if (style.radius == 0) {
			m_visual.m_type = ShapeType::RECT;
			m_visual.r_shape.setPosition(pos.x, pos.y);
		}
		else if (style.m_size == Vector2f(0, 0)) {
			m_visual.m_type = ShapeType::CIRC;
			m_visual.c_shape.setPosition(pos.x, pos.y);
		}
		else {
			m_visual.m_type = ShapeType::NONE;
		}

		updateStyle();
	}

	UI_Style m_style;
	UI_Visual m_visual;

	bool clickable = false;
	void (*clickPtr)(Menu* m, UI_Element e);

	void setPosition(Position pos) {
		m_visual.c_shape.setPosition(pos.x, pos.y);
		m_visual.r_shape.setPosition(pos.x, pos.y);
	}

	void updateStyle() {
		m_visual.c_shape.setRadius(m_style.radius);
		m_visual.c_shape.setPointCount(1000);
		m_visual.r_shape.setSize(m_style.m_size);

		// Update origin
		m_visual.r_shape.setOrigin(m_style.m_size.x / 2, m_style.m_size.y / 2);
		m_visual.c_shape.setOrigin(m_style.radius, m_style.radius);

		m_visual.c_shape.setFillColor(m_style.color);
		m_visual.r_shape.setFillColor(m_style.color);
	}
};