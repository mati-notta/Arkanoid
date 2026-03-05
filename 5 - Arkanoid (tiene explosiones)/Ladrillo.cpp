#include "Ladrillo.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Color.hpp>
using namespace sf;
using namespace std;


Ladrillo::Ladrillo(float x, float y) {
	m_Ladri.setSize(Vector2f(76.f,18.f));
	m_Ladri.setOrigin(38.f, 9.f);
	m_Ladri.setPosition(x, y);
	m_vidas = rand()%3+1;

}

FloatRect Ladrillo::getPos() const{
	return m_Ladri.getGlobalBounds();
}

void Ladrillo::Draw (RenderWindow &window){
	window.draw(m_Ladri);
}

void Ladrillo::Colorear(Color vida1, Color vida2, Color vida3){
	switch(m_vidas){
	case 1:
		m_Ladri.setFillColor(vida1);
		break;
	case 2:
		m_Ladri.setFillColor(vida2);
		break;
	case 3:
		m_Ladri.setFillColor(vida3);
		break;
		
	}
}

void Ladrillo::ModVidas(){
	m_vidas--;
	
}

int Ladrillo::VerVidas(){
	return m_vidas;
}

Ladrillo::~Ladrillo(){
	
}
