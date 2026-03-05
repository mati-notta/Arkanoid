#ifndef FINPARTIDA_H
#define FINPARTIDA_H
#include "Escena.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Clock.hpp>
#include "Juego.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <vector>
#include "Estadisticas.h"
#include "InputText.hpp"

using namespace std;
using namespace sf;

class FinPartida : public Escena {
public:
	FinPartida(int vidas, int puntaje, vector<Color> estilo, int nivel);
	void Update(Juego &game) override;
	void Draw(RenderWindow &window) override;
	void ProcesarEvento(const Event &e);
private:
	int m_vidas, m_puntaje, m_nivel;
	Font font;
	Text text, ingresoNombre;
	Clock clock;
	vector<Color> m_estilo;
	bool FinJuego;
	InputText entradaNombre;
	Estadisticas estadisticas;
};

#endif

