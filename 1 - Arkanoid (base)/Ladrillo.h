#ifndef LADRILLO_H
#define LADRILLO_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
using namespace sf;
using namespace std;

class Ladrillo : public Drawable {
public:
	Ladrillo(float x, float y);
	FloatRect getPos()const;
	void draw(RenderTarget &target, RenderStates states)const;
	~Ladrillo();
private:
	RectangleShape m_Ladri;
};

#endif

