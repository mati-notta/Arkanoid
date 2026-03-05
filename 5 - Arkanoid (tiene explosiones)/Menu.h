#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include "Escena.h"
#include "Juego.h"
#include <SFML/Graphics/Color.hpp>

using namespace sf;
using namespace std;

class Menu : public Escena {
public:
	Menu();
	void Update(Juego &game) override;
	void Draw(RenderWindow &window) override;
	~Menu();
private:
	Font font;
	Text jugar, opciones, salir;
	RectangleShape c_jugar, c_opciones, c_salir;
	int posicion;
	Clock m_clock;
	FloatRect bounds;
	vector <Color> estilo;
	Color m_fondo, m_relleno;
	bool unicaVez = true;
};
#endif
