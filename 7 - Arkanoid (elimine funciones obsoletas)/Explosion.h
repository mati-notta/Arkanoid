#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

using namespace sf;
using namespace std;

class Explosion {
public:
	Explosion(Vector2f posicion, Color color);
	void Update();
	void Draw(RenderWindow &window);
	bool Fin();
private:
	CircleShape m_particula;
	Vector2f velocidad;
	float vida, vida_max;
};
#endif

