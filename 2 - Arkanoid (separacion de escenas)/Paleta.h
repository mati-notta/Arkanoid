#ifndef PALETA_H
#define PALETA_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Rect.hpp>

using namespace sf;
using namespace std;

class Paleta : public Drawable{
public:
	Paleta();
	FloatRect getPos() const;
	void draw(RenderTarget &target, RenderStates states)const;
	void Update();
	~Paleta();
private:
	RectangleShape m_Paleta;
	float velocidad = 3.f;
};
#endif
