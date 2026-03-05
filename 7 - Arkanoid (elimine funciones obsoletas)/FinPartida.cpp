#include "FinPartida.h"
#include "Partida.h"
#include "Menu.h"

using namespace std;

FinPartida::FinPartida(int vidas, int puntaje, vector<Color> estilo, int nivel) : m_vidas(vidas), m_puntaje(puntaje), m_estilo(estilo), m_nivel(nivel){
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(80);

	if(m_vidas > 0){
		FinJuego = false;
		text.setString("Perdiste una vida... \n    Te quedan " + to_string(m_vidas)); 
		text.setPosition(410, 320);
	}else{
		FinJuego = true;
		text.setString("GAME OVER\n   Puntos: " + to_string(m_puntaje));
		text.setPosition(410,200);
		
		entradaNombre = InputText (font, 30, Color::White);
		entradaNombre.setPosition(450, 405);
		entradaNombre.setMaxChars(10);
		
		ingresoNombre.setFont(font);
		ingresoNombre.setString("ingrese su nombre: ");
		ingresoNombre.setCharacterSize(35);
		ingresoNombre.setPosition(100, 400);
	}
	FloatRect bounds = text.getLocalBounds();
	text.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

	clock.restart();
}

void FinPartida::Update(Juego &game){
	if(clock.getElapsedTime().asSeconds()>3.f){
		if (m_vidas > 0){
			int perdidas = 3 - m_vidas;
			game.CambiarEscena(new Partida(m_estilo, perdidas, m_puntaje, m_nivel));
			}else{
			entradaNombre.update();
			if(Keyboard::isKeyPressed(Keyboard::Return) && entradaNombre.getValue().size() > 0){
				estadisticas.GuardarJugador(entradaNombre.getValue(), m_puntaje);
				
				game.CambiarEscena(new Menu);
			}
		}
	}
}

void FinPartida::Draw(RenderWindow &window){
	window.clear(Color(25, 25, 25));
	window.draw(text);
	
	if(FinJuego){
		window.draw(ingresoNombre);
		window.draw(entradaNombre);
	}
}

void FinPartida::ProcesarEvento(const Event &e) {
	if(FinJuego) {
		entradaNombre.processEvent(e);
	}
}
