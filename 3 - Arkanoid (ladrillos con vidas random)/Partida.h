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
	Partida();
	void Update(Juego &game) override;
	void Reset();
	void Draw(RenderWindow &window) override;
	~Partida();
private:
	Paleta* paleta;
	Bola* bola;
	Colision choque;
	int contLadrillos, contGanar, contPerder;
	bool unicaVez;
	vector <Ladrillo> ladrillos;
	ContextSettings settings;
};
#endif
