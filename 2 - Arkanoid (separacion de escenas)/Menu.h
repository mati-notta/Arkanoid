#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include "Escena.h"
#include "Juego.h"

using namespace sf;
using namespace std;

class Menu : public Escena {
public:
	Menu();
	void Update(Juego &game) override;
	void Draw(RenderWindow &window) override;
private:
	Font font;
	Text menu, jugar, opciones, salir;
	RectangleShape c_jugar, c_opciones, c_salir;
	int posicion;
	Clock m_clock;
};
#endif
