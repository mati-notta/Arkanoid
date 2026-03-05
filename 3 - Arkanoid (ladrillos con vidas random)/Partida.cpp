#include "Partida.h"
#include "Paleta.h"
#include "Bola.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
#include "Juego.h"
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <cmath>

#include <iostream>
using namespace sf;
using namespace std;
int a=0;

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
		
		Vector2f datChoque = choque.CalChoque(bola->getPos(), it->getPos());
		
		if(datChoque.x !=0 || datChoque.y !=0){
			if(abs(datChoque.x) > abs(datChoque.y)){
				if(datChoque.y < 0){ bola->ModVelY(-4.f);}
				else{ bola->ModVelY(4.f);}
			}else{
				if(datChoque.x < 0){ bola->ModVelX(-3.f);}
				else{ bola->ModVelX(3.f);}
			}
			it->ModVidas();
			it->Colorear();
			
			if(it->VerVidas() <=0){
				contLadrillos++;
				it = ladrillos.erase(it);
			}else{
				it++;
			}
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
	paleta->draw(window);
	bola->draw(window);
	
	for(auto &Ladrillo : ladrillos) { 
		Ladrillo.draw(window);
	}
}

Partida::~Partida(){
	delete paleta;
	delete bola;
}
