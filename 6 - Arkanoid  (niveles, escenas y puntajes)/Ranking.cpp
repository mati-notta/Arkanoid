#include "Ranking.h"
#include <vector>
#include "Menu.h"
#include <string>
#include <SFML/Window/Keyboard.hpp>
using namespace std;

Ranking::Ranking() {
	font.loadFromFile("arial.ttf");
	
	text.setFont(font);
	text.setString("TOP 10 MEJORES JUGADORES");
	text.setCharacterSize(35);
	text.setFillColor(Color::Yellow);
	
	FloatRect bounds = text.getLocalBounds();
	text.setOrigin(bounds.width/2, bounds.height/2);
	text.setPosition(410, 50);
	
	volver.setCharacterSize(25);
	volver.setString("Volver");
	volver.setFont(font);
	volver.setPosition(50.f, 550.f);
	bounds = volver.getLocalBounds();
	volver.setOrigin(0, bounds.height * 0.5f);
	
	c_volver.setSize(Vector2f(100.f,40.f));
	c_volver.setOrigin(10.f, 30.f);
	c_volver.setPosition(50.f, 570.f);
	c_volver.setOutlineThickness(5);
	c_volver.setFillColor(Color(135, 206, 250, 20));
	c_volver.setOutlineColor(Color(135, 206, 250));
	
	vector<Jugador> lista = estadisticas.Leer();
	
	int i=0;	///me marca el espaciado entre renglones
	for(auto &jugad : lista){
		Text linea;
		linea.setFont(font);
		linea.setCharacterSize(25);
		linea.setFillColor(Color::White);
		string texto = string(jugad.nombre) + "-------" + to_string(jugad.puntuacion);
		linea.setString(texto);
		
		bounds = linea.getLocalBounds();
		linea.setOrigin(bounds.width/2, bounds.height/2);
		linea.setPosition(410, 120 + (i * 40));		///como los ladrillos, lo muevo verticalmente
		
		filas.push_back(linea);
		i++;
	}
}

void Ranking::Update(Juego &game){
	if(m_clock.getElapsedTime().asMilliseconds()>200){
		if(Keyboard::isKeyPressed(Keyboard::Return) || Keyboard::isKeyPressed(Keyboard::Escape)){
			game.CambiarEscena(new Menu);
		}
	}		
}

void Ranking::Draw(RenderWindow &window){
	window.clear(Color(25, 25 ,25));
	window.draw(text);
	
	for(auto &fila : filas){
		window.draw(fila);
	}
	window.draw(volver);
	window.draw(c_volver);
	
	
}
