#include "Bola.h"
#include "Paleta.h"
#include <SFML/Graphics/Rect.hpp>
#include "Ladrillo.h"
#include <cstdlib>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
using namespace std;

Bola::Bola() {
	m_Bola.setRadius(8.f);
	m_Bola.setPosition(410,600);
	m_Bola.setOrigin(8.f, 8.f);
	this->MovRand();
}

void Bola::Choque(const Paleta& paleta){
	if(m_Bola.getGlobalBounds().intersects(paleta.getPos())){
		this->MovRand();
	}
}

bool Bola::Choque(Ladrillo ladrillo){
	if(m_Bola.getGlobalBounds().intersects(ladrillo.getPos())){
		velocidad.y = -velocidad.y;
		return true;
	}else{
		return false;
	}
}

void Bola::ModVelY(float multi){
	velocidad.y = multi;
}
void Bola::ModVelX(float multi){
	velocidad.y = multi;
}

FloatRect Bola::getPos() const{
	return m_Bola.getGlobalBounds();
}

void Bola::Update(){
	m_Bola.move(velocidad);
	
	if(m_Bola.getPosition().x < (0+8) || m_Bola.getPosition().x > (820-8)){
		velocidad.x = -velocidad.x;
	}
	if(m_Bola.getPosition().y < 0){
		velocidad.y = -velocidad.y;
	}
}

bool Bola::Cae(){
	if(m_Bola.getPosition().y > 640){
		m_Bola.setPosition(410,600);
		this->MovRand();
		return true;
	}
	return false;
}

void Bola::Reinicio(){
	m_Bola.setPosition(410,600);
}

void Bola::draw (RenderWindow &window){
	window.draw(m_Bola);
}

void Bola::MovRand(){
	switch(rand()%2){
	case 0:
		velocidad = {-(rand()%3+2.f), -4.f};
		break;
	case 1:
		velocidad = {(rand()%3+2.f), -4.f};
		break;
	}
}

Bola::~Bola(){
	
}
