#include "Ladrillo.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
using namespace sf;
using namespace std;


Ladrillo::Ladrillo(float x, float y) {
	m_Ladri.setSize(Vector2f(82.f,20.f));
	m_Ladri.setOrigin(41.f, 7.5f);
	m_Ladri.setPosition(x, y);
	m_Ladri.setOutlineThickness(2.f);
	m_Ladri.setOutlineColor(Color(25,25,25));
}

FloatRect Ladrillo::getPos() const{
	return m_Ladri.getGlobalBounds();
}

void Ladrillo::draw (RenderTarget &target, RenderStates states)const{
	target.draw(m_Ladri, states);
}

Ladrillo::~Ladrillo(){
	
}
