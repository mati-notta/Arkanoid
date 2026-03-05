#ifndef GANADOR_H
#define GANADOR_H
#include "Escena.h"
#include <vector>
#include <SFML/Graphics/Color.hpp>
#include "Juego.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
using namespace std;

class Ganador : public Escena {
public:
	Ganador(int vidas, int puntaje, vector<Color> estilo, int nivel);
	void Update(Juego &game) override;
	void Draw(RenderWindow &window) override;
private:
	int m_vidas, m_puntaje, m_nivel;
	vector<Color> m_estilo;
	Font font;
	Text text;
	Clock clock;
};

#endif

