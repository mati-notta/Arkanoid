#ifndef PARTIDA_H
#define PARTIDA_H
#include "Bola.h"
#include "Paleta.h"
#include <SFML/Window/ContextSettings.hpp>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escena.h"
#include "Colision.h"

using namespace sf;
using namespace std;

class Partida : public Escena{
public:
	Partida(vector<Color> estilo);
	void Update(Juego &game) override;
	void Reset();
	void Draw(RenderWindow &window) override;
	~Partida();
private:
	Paleta* paleta;
	Bola* bola;
	Colision choque;
	int contLadrillos, contGanar, contPerder;
//	bool unicaVez;
	vector <Ladrillo> ladrillos;
	vector <Color> m_estilo;
	ContextSettings settings;
	Color fondo;
};
#endif
