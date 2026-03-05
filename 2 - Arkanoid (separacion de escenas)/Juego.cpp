#include "Juego.h"
#include "Escena.h"
#include <SFML/Window/Event.hpp>

using namespace sf;
using namespace std;

Juego::Juego(Escena *scene) : m_window(VideoMode(820,640),"Arkanoid") {
	m_window.setFramerateLimit(120);
	m_scene = scene;
}

void Juego::Iniciar(){
	while(m_window.isOpen()) {
		Event e;
		while(m_window.pollEvent(e)) {
			if(e.type == Event::Closed)
				m_window.close();	
		}
		m_scene->Update(*this);
		m_scene->Draw(m_window);
		m_window.display();
		
		if(m_proxEsc){
			delete m_scene;
			m_scene = m_proxEsc;
			m_proxEsc = nullptr;
		}
	}
}

void Juego::CambiarEscena(Escena *new_scene){
	m_proxEsc = new_scene;
}

Juego::~Juego(){
	delete m_scene;
}
