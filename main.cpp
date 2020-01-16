#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Menu.hpp"
#include "UI_Element.hpp"

using namespace std;
using namespace sf;

void clickAction(Menu* m, UI_Element e) {
	m->setBackground(m->getBgColor() == Color::White ? Color::Yellow : Color::White);
}

int main() {
	ContextSettings settings;

	settings.antialiasingLevel = 8;

	RenderWindow w;
	w.create(VideoMode(800, 800), "Strategy UI", Style::Default, settings);
	w.setVerticalSyncEnabled(true);

	Menu main(w);

	UI_Element e = UI_Element({ Color::Red, Vector2f(700, 50), 0 },
		Position(w, MarkX::CENTER_X, MarkY::CENTER_Y) + Position(100, 300),
		clickAction);
	main.addElement(e);

	UI_Element e1 = UI_Element({ Color::Green, Vector2f(0, 0), 100 },
		Position(400, 400));
	main.addElement(e1);

	while (w.isOpen()) {
		Event e;

		while (w.pollEvent(e)) {
			if (e.type == Event::Closed)
				w.close();

			main.input(e);
		}

		w.clear();

		main.draw();

		// Draw
		w.display();
	}

	return 0;
}