#include "Partida.h"
#include "Paleta.h"
#include "Bola.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
#include "Juego.h"

using namespace sf;
using namespace std;

Partida::Partida() {
	settings.antialiasingLevel = 16;
	paleta = new Paleta();
	bola = new Bola();
	contLadrillos = contGanar = contPerder = 0;
	unicaVez = false;
	
	for(int i=0;i<10;i++) { 
		for(int j=0;j<4;j++) { 
			ladrillos.push_back(Ladrillo(41 + 82*i, 25 + 25*j));
		}
	}
}

void Partida::Update(Juego &game){
	paleta->Update();
	bola->Choque(*paleta);
	bola->Update();
	if(Keyboard::isKeyPressed(Keyboard::Escape)) game.CambiarEscena(new Menu);
	
	for(auto it = ladrillos.begin(); it!=ladrillos.end();){
		if(bola->Choque(*it)){
			contLadrillos++;
			it = ladrillos.erase(it);
		}else{
			it++;
		}
	}
	if (ladrillos.empty()){
		
	}
	if(bola->Cae()){
		Reset();
		contPerder++;
		if(contPerder>=3) game.CambiarEscena(new Menu);
	}
}

void Partida::Reset(){
	bola->Reinicio();
	ladrillos.clear();
	
	for(int i=0;i<10;i++) { 
		for(int j=0;j<4;j++) { 
			ladrillos.push_back(Ladrillo (41 + 82*i, 25 + 25*j));
		}
	}
}

void Partida::Draw(RenderWindow &window){
	window.clear(Color(25,25,25));
	window.draw(*paleta);
	window.draw(*bola);
	
	for(auto Ladrillo : ladrillos) { 
		window.draw(Ladrillo);
	}
}

Partida::~Partida(){
	delete paleta;
	delete bola;
}
