#include "Paleta.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Rect.hpp>

using namespace sf;
using namespace std;
float Ancho = 80; float mAncho = Ancho/2;
float Largo = 10; float mLargo = Largo/2;

Paleta::Paleta() {
	m_Paleta.setSize(Vector2f(Ancho, Largo));
	m_Paleta.setPosition(410,630);
	m_Paleta.setOrigin(mAncho, mLargo);
}

FloatRect Paleta::getPos() const{
	return m_Paleta.getGlobalBounds();
}

void Paleta::Update(){
	if(Keyboard::isKeyPressed(Keyboard::A) && m_Paleta.getPosition().x - Ancho > (0 - mAncho)){
		m_Paleta.move(-velocidad,0);
	}
	if(Keyboard::isKeyPressed(Keyboard::D) && m_Paleta.getPosition().x + Ancho < (820 + mAncho)){
		m_Paleta.move(velocidad,0);
	}
	if(Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::LShift) && m_Paleta.getPosition().x - Ancho > (0 - mAncho)){
		m_Paleta.move(-velocidad * 1.2,0);
	}
	if(Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift) && m_Paleta.getPosition().x + Ancho < (820 + mAncho)){
		m_Paleta.move(velocidad * 1.2,0);
	}
}

void Paleta::draw (RenderTarget &target, RenderStates states)const{
	target.draw(m_Paleta, states);
}

Paleta::~Paleta(){
	
}
