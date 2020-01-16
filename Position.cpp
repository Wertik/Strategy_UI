#pragma once

#include <SFML/Graphics.hpp>

#include "Position.hpp"

using namespace sf;

Position::Position() {

}

Position::Position(float _x, float _y) {
	x = _x;
	y = _y;
}

Position::Position(Vector2f v) {
	x = v.x;
	y = v.y;
}

Position::Position(RenderWindow& w, MarkX _x, MarkY _y) {
	mark_x = _x;
	mark_y = _y;

	switch (_x) {
	case MarkX::LEFT:
		x = 0;
		break;
	case MarkX::RIGHT:
		x = w.getSize().x;
		break;
	case MarkX::CENTER_X:
		x = w.getSize().x / 2;
		break;
	}

	switch (_y) {
	case MarkY::TOP:
		y = 0;
		break;
	case MarkY::BOTTOM:
		y = w.getSize().y;
		break;
	case MarkY::CENTER_Y:
		y = w.getSize().y / 2;
		break;
	}
}

Position Position::random(Position b_x, Position b_y) {
	int max_x = std::abs(b_x.x) + std::abs(b_x.y);

	float x = rand() % max_x;

	if (x < std::abs(b_x.x))
		x *= -1;

	int max_y = std::abs(b_y.x) + std::abs(b_y.y);

	float y = rand() % max_y;

	if (y < std::abs(b_y.x))
		y *= -1;

	return Position(x, y);
}

void Position::randomize(int b_x, int b_y) {
	// Position rnd = random(b_x, b_y);

	// x = rnd.x;
	// y = rnd.y;
}

Position Position::add(Position pos) {
	return Position(pos.x + x, pos.y + y);
}

Position Position::operator+(Position arg) {
	return Position(x + arg.x, y + arg.y);
}

void Position::operator=(Position arg) {
	x = arg.x;
	y = arg.y;
}

bool Position::operator==(Position arg) {
	return x == arg.x && y == arg.y;
}

void Position::operator+=(Position arg) {
	x += arg.x;
	y += arg.y;
}

void Position::operator+=(Vector2f arg) {
	x += arg.x;
	y += arg.y;
}

Position Position::operator*(Position arg) {
	return Position(x * arg.x, y * arg.y);
}

Position Position::operator*(float a) {
	return Position(x * a, a * y);
}

Position Position::operator-(Position arg) {
	return Position(x - arg.x, y - arg.y);
}

float Position::abs() {
	return sqrt(pow(x, 2) + pow(y, 2));
}

float Position::dist(Position pos) {
	Position rel_pos = pos - Position(x, y);
	return rel_pos.abs();
}

void Position::operator=(Vector2f arg) {
	x = arg.x;
	y = arg.y;
}

Vector2f Position::toVector() {
	return Vector2f(x, y);
}

Position Position::fromVector(Vector2f v) {
	return Position(v);
}