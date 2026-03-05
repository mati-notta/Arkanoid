#include "Bola.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "Paleta.h"
#include <SFML/Graphics/Rect.hpp>
#include "Ladrillo.h"
#include <cstdlib>
using namespace sf;
using namespace std;

Bola::Bola() {
	m_Bola.setRadius(8.f);
	m_Bola.setPosition(320, 420);
	m_Bola.setOrigin(8.f, 8.f);
	
	switch(rand()%2){
	case 0:
		velocidad = {-(rand()%3+2.f), -3.f};
		break;
	case 1:
		velocidad = {(rand()%3+2.f), -3.f};
		break;
	}
}

void Bola::Choque(const Paleta& paleta){
	if(m_Bola.getGlobalBounds().intersects(paleta.getPos())){
		switch(rand()%2){
		case 0:
			velocidad = {3, -3};
			break;
		case 1:
			velocidad = {-3, -3};
			break;
		}
	}
}

bool Bola::Choque(Ladrillo* ladrillo){
	if(m_Bola.getGlobalBounds().intersects(ladrillo->getPos())){
		velocidad.y = -velocidad.y;
		return true;
	}else{
		return false;
	}
}

FloatRect Bola::getPos() const{
	return m_Bola.getGlobalBounds();
}

void Bola::Update(){
	m_Bola.move(velocidad);
	
	if(m_Bola.getPosition().x < 0 || m_Bola.getPosition().x > 640){
		velocidad.x = -velocidad.x;
	}
	if(m_Bola.getPosition().y < 0){
		velocidad.y = -velocidad.y;
	}
}

bool Bola::Cae(){
	if(m_Bola.getPosition().y > 480){
		m_Bola.setPosition(320, 420);
		switch(rand()%2){
		case 0:
			velocidad = {-(rand()%3+2.f), -3.f};
			break;
		case 1:
			velocidad = {(rand()%3+2.f), -3.f};
			break;
		}
		return true;
	}
	return false;
}

void Bola::Reinicio(){
	m_Bola.setPosition(320, 420);
}

void Bola::draw (RenderTarget &target, RenderStates states)const{
	target.draw(m_Bola, states);
}

Bola::~Bola(){
	
}
