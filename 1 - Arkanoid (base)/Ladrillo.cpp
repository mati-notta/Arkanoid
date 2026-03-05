#include "Ladrillo.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
using namespace sf;
using namespace std;

Ladrillo::Ladrillo(float x, float y) {
	m_Ladri.setSize(Vector2f(65.f,15.f));
	m_Ladri.setOrigin(30.f, 10.f);
	m_Ladri.setPosition(x, y);
}

FloatRect Ladrillo::getPos() const{
	return m_Ladri.getGlobalBounds();
}

void Ladrillo::draw (RenderTarget &target, RenderStates states)const{
	target.draw(m_Ladri, states);
}

Ladrillo::~Ladrillo(){
	
}
