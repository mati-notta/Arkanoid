#ifndef LADRILLO_H
#define LADRILLO_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;
using namespace std;

class Ladrillo {
public:
	Ladrillo(float x, float y);
	FloatRect getPos()const;
	void Colorear();
	void ModVidas();
	int VerVidas();
	void draw(RenderWindow &Window);
	~Ladrillo();
private:
	RectangleShape m_Ladri;
	int m_vidas;
};

#endif
