#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

enum class MarkX {
	NONE,
	LEFT,
	RIGHT,
	CENTER_X
};

enum class MarkY {
	NONE,
	TOP,
	BOTTOM,
	CENTER_Y
};

class Position {
public:
	float x = 0;
	float y = 0;

	MarkX mark_x = MarkX::NONE;
	MarkY mark_y = MarkY::NONE;

	Position();
	Position(Vector2f v);
	Position(float _x, float _y);
	Position(sf::RenderWindow& w, MarkX x, MarkY y);

	Position add(Position pos);

	static Position random(Position b_x, Position b_y);
	void randomize(int bound_x, int bound_y);

	float abs();
	// Calculate distance to another position
	float dist(Position pos);

	static Position fromVector(Vector2f v);

	Vector2f toVector();

	void operator=(Position arg);
	void operator=(Vector2f arg);
	Position operator+(Position arg);
	bool operator==(Position arg);
	void operator+=(sf::Vector2f arg);
	void operator+=(Position arg);
	Position operator*(Position arg);
	Position operator*(float x);
	Position operator-(Position arg);
};
