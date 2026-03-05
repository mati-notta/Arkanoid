#ifndef BOLA_H
#define BOLA_H
#include "Paleta.h"
#include "Ladrillo.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;
using namespace std;

class Bola {
public:
	Bola();
	void Choque(const Paleta& paleta);
	bool Choque(Ladrillo ladrillo);
	bool Cae();
	void Reinicio();
	void MovRand();
	void ModVelY(float multi);
	void ModVelX(float multi);
	FloatRect getPos() const;
	void draw(RenderWindow &Window);
	void Update();
	~Bola();
private:
	CircleShape m_Bola;
	Vector2f velocidad;
};
#endif
