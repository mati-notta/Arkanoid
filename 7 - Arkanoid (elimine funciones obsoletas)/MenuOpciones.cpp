#include "MenuOpciones.h"
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
#include "Estilos.h"

MenuOpciones::MenuOpciones() {
	posicion = 1;
	font.loadFromFile("arial.ttf");
	m_clock.restart();
	///													Boton Estilos
	estilos.setCharacterSize(50);
	estilos.setString("Estilos");
	estilos.setFont(font);
	estilos.setPosition(100.0f,150.0f);
	bounds = estilos.getLocalBounds();
	estilos.setOrigin(0, bounds.height * 0.5f);
	
	c_estilos.setSize(Vector2f(200.f,80.f));
	c_estilos.setOrigin(10.f, 30.f);
	c_estilos.setPosition(100.f, 150.f);
	c_estilos.setOutlineThickness(5);
	///													Boton Audios
	audio.setCharacterSize(50);
	audio.setString("Audio");
	audio.setFont(font);
	audio.setPosition(100.0f,300.0f);
	bounds = audio.getLocalBounds();
	audio.setOrigin(0, bounds.height * 0.5f);
	
	c_audio.setSize(Vector2f(200.f,80.f));
	c_audio.setOrigin(10.f, 30.f);
	c_audio.setPosition(100.f, 300.f);
	c_audio.setOutlineThickness(5);
	///													Boton Volver
	volver.setCharacterSize(50);
	volver.setString("Volver");
	volver.setFont(font);
	volver.setPosition(100.0f,450.0f);
	bounds = volver.getLocalBounds();
	volver.setOrigin(0, bounds.height * 0.5f);
	
	c_volver.setSize(Vector2f(200.f,80.f));
	c_volver.setOrigin(10.f, 30.f);
	c_volver.setPosition(100.f, 450.f);
	c_volver.setOutlineThickness(5);
}

void MenuOpciones::Update(Juego &game){
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
			if(posicion==1) game.CambiarEscena(new Estilos);
		}
	}
	if(posicion<1) posicion=3;
	if(posicion>3) posicion=1;
	switch(posicion){
	case 1:
		c_estilos.setFillColor(Color(135, 206, 250, 20));
		c_estilos.setOutlineColor(Color(135, 206, 250));
		c_audio.setFillColor(Color(25,25,25,0));
		c_audio.setOutlineColor(Color::White);
		c_volver.setFillColor(Color(25,25,25,0));
		c_volver.setOutlineColor(Color::White);
		break;
	case 2:
		c_audio.setFillColor(Color(135, 206, 250, 20));
		c_audio.setOutlineColor(Color(135, 206, 250));
		c_estilos.setFillColor(Color(25,25,25,0));
		c_estilos.setOutlineColor(Color::White);
		c_volver.setFillColor(Color(25,25,25,0));
		c_volver.setOutlineColor(Color::White);
		break;
	case 3:
		c_volver.setFillColor(Color(135, 206, 250, 20));
		c_volver.setOutlineColor(Color(135, 206, 250));
		c_estilos.setFillColor(Color(25,25,25,0));
		c_estilos.setOutlineColor(Color::White);
		c_audio.setFillColor(Color(25,25,25,0));
		c_audio.setOutlineColor(Color::White);
		if(Keyboard::isKeyPressed(Keyboard::Return)){game.CambiarEscena(new Menu);}
		break;
	}
}

void MenuOpciones::Draw(RenderWindow &window){
	window.clear(m_fondo);
	
	window.draw(estilos);
	window.draw(audio);
	window.draw(volver);
	
	window.draw(c_estilos);
	window.draw(c_audio);
	window.draw(c_volver);
}
