#include "Estilos.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "MenuOpciones.h"

Estilos::Estilos() {
	posicion = 1;
	font.loadFromFile("arial.ttf");
	m_clock.restart();
	///													Estilo Azulado
	estiloAzulado.setCharacterSize(50);
	estiloAzulado.setString("Azulado");
	estiloAzulado.setFont(font);
	estiloAzulado.setPosition(100.0f,100.0f);
	bounds = estiloAzulado.getLocalBounds();
	estiloAzulado.setOrigin(0, bounds.height * 0.5f);
	
	c_estiloAzulado.setSize(Vector2f(250.f,80.f));
	c_estiloAzulado.setOrigin(10.f, 30.f);
	c_estiloAzulado.setPosition(100.f, 100.f);
	c_estiloAzulado.setOutlineThickness(5);
	///													Estilo Rojizo
	estiloRojizo.setCharacterSize(50);
	estiloRojizo.setString("Rojizo");
	estiloRojizo.setFont(font);
	estiloRojizo.setPosition(100.0f,200.0f);
	bounds = estiloRojizo.getLocalBounds();
	estiloRojizo.setOrigin(0, bounds.height * 0.5f);
	
	c_estiloRojizo.setSize(Vector2f(250.f,80.f));
	c_estiloRojizo.setOrigin(10.f, 30.f);
	c_estiloRojizo.setPosition(100.f, 200.f);
	c_estiloRojizo.setOutlineThickness(5);
	///													Estilo Grisaceo
	estiloGris.setCharacterSize(50);
	estiloGris.setString("Grisaceo");
	estiloGris.setFont(font);
	estiloGris.setPosition(100.0f,300.0f);
	bounds = estiloGris.getLocalBounds();
	estiloGris.setOrigin(0, bounds.height * 0.5f);
	
	c_estiloGris.setSize(Vector2f(250.f,80.f));
	c_estiloGris.setOrigin(10.f, 30.f);
	c_estiloGris.setPosition(100.f, 300.f);
	c_estiloGris.setOutlineThickness(5);
	///													Estilo Calido
	estiloCalido.setCharacterSize(50);
	estiloCalido.setString("Calido");
	estiloCalido.setFont(font);
	estiloCalido.setPosition(100.0f,400.0f);
	bounds = estiloCalido.getLocalBounds();
	estiloCalido.setOrigin(0, bounds.height * 0.5f);
	
	c_estiloCalido.setSize(Vector2f(250.f,80.f));
	c_estiloCalido.setOrigin(10.f, 30.f);
	c_estiloCalido.setPosition(100.f, 400.f);
	c_estiloCalido.setOutlineThickness(5);
	///													Estilo Violaceo	
	estiloViolaceo.setCharacterSize(50);
	estiloViolaceo.setString("Violaceo");
	estiloViolaceo.setFont(font);
	estiloViolaceo.setPosition(100.0f,500.0f);
	bounds = estiloViolaceo.getLocalBounds();
	estiloViolaceo.setOrigin(0, bounds.height * 0.5f);
	
	c_estiloViolaceo.setSize(Vector2f(250.f,80.f));
	c_estiloViolaceo.setOrigin(10.f, 30.f);
	c_estiloViolaceo.setPosition(100.f, 500.f);
	c_estiloViolaceo.setOutlineThickness(5);
	
	
}

void Estilos::Update(Juego &game){
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
		if(Keyboard::isKeyPressed(Keyboard::Return)){
			if(posicion==1){
				colores.push_back(Color(112, 128, 144));	/// Fondo
				colores.push_back(Color(244, 235, 219));		/// Vida 1
				colores.push_back(Color(83, 112, 114));	  	/// Vida 2
				colores.push_back(Color(44, 74, 82));   	/// Vida 3		
				colores.push_back(Color(25, 25, 25, 50));	/// Relleno de botones
			}
			if(posicion==2){
				colores.push_back(Color(217, 177, 150));
				colores.push_back(Color(179, 113, 52));
				colores.push_back(Color(179, 3, 3));
				colores.push_back(Color(141, 10, 10));
				colores.push_back(Color(25, 25, 25, 50));
			}
			if(posicion==3){
				colores.push_back(Color(112, 111, 116));
				colores.push_back(Color(198, 198, 198));
				colores.push_back(Color(78, 89, 93));
				colores.push_back(Color(54, 61, 59));
				colores.push_back(Color(25, 25, 25, 50));
			}
			if(posicion==4){
				colores.push_back(Color(162, 157, 125));
				colores.push_back(Color(201, 166, 107));
				colores.push_back(Color(175, 68, 37));
				colores.push_back(Color(102, 46, 28));
				colores.push_back(Color(25, 25, 25, 50));
			}
			if(posicion==5){
				colores.push_back(Color(169, 124, 209));
				colores.push_back(Color(249, 223, 255));
				colores.push_back(Color(209, 164, 249));
				colores.push_back(Color(105, 61, 141));
				colores.push_back(Color(25, 25, 25, 50));
			}
			game.GuardarEstilo(colores);
			if(Keyboard::isKeyPressed(Keyboard::Return)) game.CambiarEscena(new MenuOpciones);
		}
	}
	if(posicion<1) posicion=5;
	if(posicion>5) posicion=1;
	switch(posicion){
	case 1:
		c_estiloAzulado.setFillColor(Color(135, 206, 250, 20));
		c_estiloAzulado.setOutlineColor(Color(135, 206, 250));
	
		c_estiloRojizo.setFillColor(Color(25,25,25,0));
		c_estiloRojizo.setOutlineColor(Color::White);
		c_estiloGris.setFillColor(Color(25,25,25,0));
		c_estiloGris.setOutlineColor(Color::White);
		c_estiloCalido.setFillColor(Color(25,25,25,0));
		c_estiloCalido.setOutlineColor(Color::White);
		c_estiloViolaceo.setFillColor(Color(25,25,25,0));
		c_estiloViolaceo.setOutlineColor(Color::White);
		break;
	case 2:
		c_estiloRojizo.setFillColor(Color(135, 206, 250, 20));
		c_estiloRojizo.setOutlineColor(Color(135, 206, 250));
		
		c_estiloAzulado.setFillColor(Color(25,25,25,0));
		c_estiloAzulado.setOutlineColor(Color::White);
		c_estiloGris.setFillColor(Color(25,25,25,0));
		c_estiloGris.setOutlineColor(Color::White);
		c_estiloCalido.setFillColor(Color(25,25,25,0));
		c_estiloCalido.setOutlineColor(Color::White);
		c_estiloViolaceo.setFillColor(Color(25,25,25,0));
		c_estiloViolaceo.setOutlineColor(Color::White);
		break;
	case 3:
		c_estiloGris.setFillColor(Color(135, 206, 250, 20));
		c_estiloGris.setOutlineColor(Color(135, 206, 250));
		
		c_estiloAzulado.setFillColor(Color(25,25,25,0));
		c_estiloAzulado.setOutlineColor(Color::White);
		c_estiloRojizo.setFillColor(Color(25,25,25,0));
		c_estiloRojizo.setOutlineColor(Color::White);
		c_estiloCalido.setFillColor(Color(25,25,25,0));
		c_estiloCalido.setOutlineColor(Color::White);
		c_estiloViolaceo.setFillColor(Color(25,25,25,0));
		c_estiloViolaceo.setOutlineColor(Color::White);
		break;
	case 4:
		c_estiloCalido.setFillColor(Color(135, 206, 250, 20));
		c_estiloCalido.setOutlineColor(Color(135, 206, 250));
		
		c_estiloAzulado.setFillColor(Color(25,25,25,0));
		c_estiloAzulado.setOutlineColor(Color::White);
		c_estiloRojizo.setFillColor(Color(25,25,25,0));
		c_estiloRojizo.setOutlineColor(Color::White);
		c_estiloGris.setFillColor(Color(25,25,25,0));
		c_estiloGris.setOutlineColor(Color::White);
		c_estiloViolaceo.setFillColor(Color(25,25,25,0));
		c_estiloViolaceo.setOutlineColor(Color::White);
		break;
	case 5:
		c_estiloViolaceo.setFillColor(Color(135, 206, 250, 20));
		c_estiloViolaceo.setOutlineColor(Color(135, 206, 250));
		
		c_estiloAzulado.setFillColor(Color(25,25,25,0));
		c_estiloAzulado.setOutlineColor(Color::White);
		c_estiloRojizo.setFillColor(Color(25,25,25,0));
		c_estiloRojizo.setOutlineColor(Color::White);
		c_estiloGris.setFillColor(Color(25,25,25,0));
		c_estiloGris.setOutlineColor(Color::White);
		c_estiloCalido.setFillColor(Color(25,25,25,0));
		c_estiloCalido.setOutlineColor(Color::White);
		break;
	}
}


void Estilos::Draw(RenderWindow &window){
	window.clear(m_fondo);
	
	window.draw(estiloAzulado);
	window.draw(estiloRojizo);
	window.draw(estiloGris);
	window.draw(estiloCalido);
	window.draw(estiloViolaceo);
	
	window.draw(c_estiloAzulado);
	window.draw(c_estiloRojizo);
	window.draw(c_estiloGris);
	window.draw(c_estiloCalido);
	window.draw(c_estiloViolaceo);
}

