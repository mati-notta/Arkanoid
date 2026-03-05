#include "Juego.h"
#include "Escena.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Color.hpp>

using namespace sf;
using namespace std;

Juego::Juego(Escena *scene) : m_window(VideoMode(820,640),"Arkanoid") {
	m_window.setFramerateLimit(120);
	m_scene = scene;
	m_coloresActuales = {Color(142, 155, 151), Color(244, 235, 219), Color(83, 112, 114), Color(44, 74, 82)};
}

void Juego::Iniciar(){
	while(m_window.isOpen()) {
		Event e;
		while(m_window.pollEvent(e)) {
			if(e.type == Event::Closed)
				m_window.close();
			if(m_scene) m_scene->ProcesarEvento(e);
		}
		m_scene->Update(*this);
		m_scene->Draw(m_window);
		m_window.display();
		
		if(m_proxEsc){				///sacado del video
			delete m_scene;
			m_scene = m_proxEsc;
			m_proxEsc = nullptr;
		}
	}
}

void Juego::GuardarEstilo(vector<Color>colores){
	m_coloresActuales = colores;
}

vector<Color> Juego::verEstilo(){
	return m_coloresActuales;
}

void Juego::CambiarEscena(Escena *new_scene){
	m_proxEsc = new_scene;
}

Juego::~Juego(){
	delete m_scene;
}
