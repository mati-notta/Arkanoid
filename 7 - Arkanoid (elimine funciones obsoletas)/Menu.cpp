#include "Menu.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include "Partida.h"
#include "MenuOpciones.h"
#include "Ranking.h"

using namespace sf;
using namespace std;

Menu::Menu() {
	posicion = 1;
	font.loadFromFile("arial.ttf");
	m_clock.restart();
	///													Boton Jugar
	jugar.setCharacterSize(50);
	jugar.setString("Jugar");
	jugar.setFont(font);
	jugar.setPosition(100.f, 150.f);
	bounds = jugar.getLocalBounds();
	jugar.setOrigin(0, bounds.height * 0.5f);
	
	c_jugar.setSize(Vector2f(200.f,80.f));
	c_jugar.setOrigin(10.f, 30.f);
	c_jugar.setPosition(100.f, 150.f);
	c_jugar.setOutlineThickness(5);
	///													Boton Opciones
	opciones.setCharacterSize(50);
	opciones.setString("Opciones");
	opciones.setFont(font);
	opciones.setPosition(100.0f,300.0f);
	bounds = opciones.getLocalBounds();
	opciones.setOrigin(0, bounds.height * 0.5f);
	c_opciones.setSize(Vector2f(280.f,80.f));
	c_opciones.setOrigin(10.f, 30.f);
	c_opciones.setPosition(100.f, 300.f);
	c_opciones.setOutlineThickness(5);
	///													Boton Salir
	salir.setCharacterSize(50);
	salir.setString("Salir");
	salir.setFont(font);
	salir.setPosition(100.f, 450.f);
	bounds = salir.getLocalBounds();
	salir.setOrigin(0, bounds.height * 0.5f);
	
	c_salir.setSize(Vector2f(200.f,80.f));
	c_salir.setOrigin(10.f, 30.f);
	c_salir.setPosition(100.f, 450.f);
	c_salir.setOutlineThickness(5);
	///													Boton Ranking
	ranking.setCharacterSize(35);
	ranking.setString("Ranking");
	ranking.setFont(font);
	ranking.setPosition(600.f, 50.f);
	bounds = ranking.getLocalBounds();
	ranking.setOrigin(0, bounds.height * 0.5f);

	c_ranking.setSize(Vector2f(150.f,70.f));
	c_ranking.setOrigin(10.f, 30.f);
	c_ranking.setPosition(600.f, 50.f);
	c_ranking.setOutlineThickness(5);
}

void Menu::Update(Juego &game){
	while(unicaVez){
		estilo = game.verEstilo();
		m_fondo = estilo[0];
		unicaVez = false;
	}
	if(m_clock.getElapsedTime().asMilliseconds()>200){
		if(Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)){
			posicion--;
			m_clock.restart();
		}
		if(Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)){
			posicion++;
			m_clock.restart();
		}
		if(Keyboard::isKeyPressed(Keyboard::Return)){		///cambios de escenas
			if(posicion==0){
				game.CambiarEscena(new Ranking);
			}
			if(posicion==1){
				game.CambiarEscena(new Partida(estilo, 0, 0, 1));
			}
			if(posicion==2) {
			   game.CambiarEscena(new MenuOpciones);
			}
			
		}
		
	}
	
	if(posicion<0) posicion=3;
	if(posicion>3) posicion=0;
	switch(posicion){										///cambio de fondos
	case 0:
		c_ranking.setFillColor(Color(135, 206, 250, 20));
		c_ranking.setOutlineColor(Color(135, 206, 250));
		c_opciones.setFillColor(Color(25,25,25,0));
		c_opciones.setOutlineColor(Color::White);
		c_jugar.setFillColor(Color(25,25,25,0));
		c_jugar.setOutlineColor(Color::White);
		c_salir.setFillColor(Color(25,25,25,0));
		c_salir.setOutlineColor(Color::White);
		break;
	case 1:
		c_jugar.setFillColor(Color(135, 206, 250, 20));
		c_jugar.setOutlineColor(Color(135, 206, 250));
		c_opciones.setFillColor(Color(25,25,25,0));
		c_opciones.setOutlineColor(Color::White);
		c_salir.setFillColor(Color(25,25,25,0));
		c_salir.setOutlineColor(Color::White);
		c_ranking.setFillColor(Color(25,25,25,0));
		c_ranking.setOutlineColor(Color::White);
		break;
	case 2:
		c_opciones.setFillColor(Color(135, 206, 250, 20));
		c_opciones.setOutlineColor(Color(135, 206, 250));
		c_jugar.setFillColor(Color(25,25,25,0));
		c_jugar.setOutlineColor(Color::White);
		c_salir.setFillColor(Color(25,25,25,0));
		c_salir.setOutlineColor(Color::White);
		c_ranking.setFillColor(Color(25,25,25,0));
		c_ranking.setOutlineColor(Color::White);
		break;
	case 3:
		c_salir.setFillColor(Color(135, 206, 250, 20));
		c_salir.setOutlineColor(Color(135, 206, 250));
		c_opciones.setFillColor(Color(25,25,25,0));
		c_opciones.setOutlineColor(Color::White);
		c_jugar.setFillColor(Color(25,25,25,0));
		c_jugar.setOutlineColor(Color::White);
		c_ranking.setFillColor(Color(25,25,25,0));
		c_ranking.setOutlineColor(Color::White);
		break;
	}
}

void Menu::Draw(RenderWindow &window){
	if(posicion==3 && Keyboard::isKeyPressed(Keyboard::Return)) window.close();
	window.clear(m_fondo);
	
	window.draw(ranking);
	window.draw(jugar);
	window.draw(opciones);
	window.draw(salir);
	
	window.draw(c_ranking);
	window.draw(c_jugar);
	window.draw(c_opciones);
	window.draw(c_salir);
}
