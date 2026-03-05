#include "Ganador.h"
#include "Partida.h"

Ganador::Ganador(int vidas, int puntaje, vector<Color> estilo, int nivel) : m_vidas(vidas), m_puntaje(puntaje), m_estilo(estilo), m_nivel(nivel) {
	
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setString("	Felicidades!\nPasaste al Nivel " + to_string(m_nivel + 1));
	text.setCharacterSize(70);
	text.setFillColor(Color::White);
	
	FloatRect bounds = text.getLocalBounds();
	text.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
	text.setPosition(410, 250);
	clock.restart();
}

void Ganador::Update(Juego &game){
	if(clock.getElapsedTime().asSeconds() > 3.0f){
		int vidas = 3 - m_vidas;
		game.CambiarEscena(new Partida(m_estilo, vidas, m_puntaje, m_nivel + 1));
	}
}

void Ganador::Draw(RenderWindow &window){
	window.clear(Color(25, 25, 25));
	window.draw(text);
}
