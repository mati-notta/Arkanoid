#ifndef RANKING_H
#define RANKING_H
#include "Estadisticas.h"
#include <vector>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include <SFML/Graphics/RectangleShape.hpp>
using namespace std;
using namespace sf;

class Ranking : public Escena {
public:
	Ranking();
	void Update(Juego &game) override;
	void Draw(RenderWindow &window) override;
private:
	Font font;
	Text text, volver;
	RectangleShape c_volver;
	vector<Text> filas;
	Estadisticas estadisticas;
	Clock m_clock;
};

#endif

