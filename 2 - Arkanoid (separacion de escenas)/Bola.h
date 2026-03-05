#ifndef BOLA_H
#define BOLA_H
#include "Paleta.h"
#include "Ladrillo.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;
using namespace std;

class Bola : public Drawable {
public:
	Bola();
	void Choque(const Paleta& paleta);
	bool Choque(Ladrillo ladrillo);
	bool Cae();
	void Reinicio();
	void MovRand();
	FloatRect getPos() const;
	void draw(RenderTarget &target, RenderStates states)const;
	void Update();
	~Bola();
private:
	CircleShape m_Bola;
	Vector2f velocidad ;
};
#endif
