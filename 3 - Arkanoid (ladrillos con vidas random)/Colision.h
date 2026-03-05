#ifndef COLISION_H
#define COLISION_H
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
using namespace std;
using namespace sf;
class Colision {
public:
	Colision();
	Vector2f CalChoque(FloatRect bola, FloatRect ladrillo);
	~Colision();
private:
};
#endif

