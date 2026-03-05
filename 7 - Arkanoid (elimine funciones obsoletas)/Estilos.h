#ifndef ESTILOS_H
#define ESTILOS_H
#include "Juego.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include <SFML/Graphics/Color.hpp>

using namespace std;

class Estilos : public Escena{
public:
	Estilos();
	void Update(Juego &game) override;
	void Draw(RenderWindow &window) override;
private:
	int posicion;
	Color m_fondo;
	vector<Color> colores, estilo;
	bool unicaVez = true;
	Clock m_clock;
	FloatRect bounds;
	Font font;
	RectangleShape c_estiloAzulado, c_estiloRojizo, c_estiloGris, c_estiloCalido, c_estiloViolaceo;
	Text estiloAzulado, estiloRojizo, estiloGris, estiloCalido, estiloViolaceo;
};

#endif
