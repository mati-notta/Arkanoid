#ifndef MENUOPCIONES_H
#define MENUOPCIONES_H
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Juego.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>

class MenuOpciones : public Escena {
public:
	MenuOpciones();
	void Update(Juego &game) override;
	void Draw(RenderWindow &window) override;
private:
	Clock m_clock;
	FloatRect bounds;
	Font font;
	RectangleShape c_estilos, c_audio, c_volver;
	Text estilos, audio, volver;
	int posicion;
	Color m_fondo;
	bool unicaVez = true;
	vector <Color> estilo;
};

#endif

