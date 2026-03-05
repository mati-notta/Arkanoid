#ifndef PARTIDA_H
#define PARTIDA_H
#include "Bola.h"
#include "Paleta.h"
#include <SFML/Window/ContextSettings.hpp>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escena.h"
#include "Colision.h"
#include "Explosion.h"
#include <SFML/System/Vector2.hpp>

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
	vector <Ladrillo> ladrillos;
	vector <Color> m_estilo;
	vector <Explosion> particulas;
	ContextSettings settings;
	Color fondo;
	Vector2f midLadrillo;
};
#endif
