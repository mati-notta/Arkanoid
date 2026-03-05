#ifndef PALETA_H
#define PALETA_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;
using namespace std;

class Paleta {
public:
	Paleta();
	FloatRect getPos() const;
	void Draw(RenderWindow &Window);
	void Update();
	~Paleta();
private:
	RectangleShape m_Paleta;
	float velocidad = 3.f;
	float Ancho = 80, mAncho = Ancho/2;
	float Largo = 10, mLargo = Largo/2;
};
#endif
