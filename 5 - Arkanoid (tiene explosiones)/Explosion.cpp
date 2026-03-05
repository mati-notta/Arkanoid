#include "Explosion.h"

Explosion::Explosion(Vector2f posicion, Color color) {
	m_particula.setPosition(posicion);
	m_particula.setRadius(4.f);
	m_particula.setFillColor(color);
	m_particula.setOrigin(4.f, 4.f);
	
	vida_max = rand()%1000+1000;
	vida = vida_max;
	velocidad = {(rand()%40-20)/30.f, (rand()%40-20)/30.f};
}

void Explosion::Update(){
	m_particula.move(velocidad);
	vida--;
	
	if(vida>0){
		Color color = m_particula.getFillColor();
		float medio = vida / vida_max;
		color.a = static_cast<Uint8>(255*medio); ///la a es opacidad (Alpha)
		m_particula.setFillColor(color);
	}
}

bool Explosion::Fin(){
	return (vida<=0);
}

void Explosion::Draw(RenderWindow &window){
	window.draw(m_particula);
}

