#include <SFML/Graphics.hpp>
#include "Paleta.h"
#include "Bola.h"
#include <SFML/Window/WindowStyle.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include "Ladrillo.h"
#include <fstream>
using namespace std;
using namespace sf;

enum{
	MainMenu,
	PlayGame,
	winMenu,
	endMenu,
	pausa
};

int main(int argc, char *argv[]){
	ContextSettings settings;
	settings.antialiasingLevel = 16;
	RenderWindow w(VideoMode(640,480),"Arkanoid", Style::Default, settings);
	w.setFramerateLimit(120);
	Paleta* paleta;
	paleta = new Paleta();
	Bola* bola;
	bola = new Bola();
	
	int contLadrillos, contGanar, contPerder;
	contLadrillos = contGanar = contPerder = 0;
	bool unicaVez = false;
	
	vector <Ladrillo*> ladrillos;
	for(int i=0;i<9;i++) { 
		for(int j=0;j<8;j++) { 
			ladrillos.push_back(new Ladrillo (35 + 70*i, 25 + 20*j));
		}
	}
	
	Font font;
	font.loadFromFile("arial.ttf");
	Text menu;
	menu.setCharacterSize(30);
	menu.setString("--- presiona ENTER ---");
	menu.setFont(font);
	menu.setPosition(320.0f, 240.0f);
	FloatRect bounds = menu.getLocalBounds();
	menu.setOrigin(bounds.width * 0.5f, bounds.height * 0.5f);
	
	int gameState = MainMenu;
	
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		
		if(gameState == MainMenu){
			menu.setString("--- presiona ENTER ---");
			
			w.clear(Color(25,25,25));
			w.draw(menu);
			w.display();
			if(Keyboard::isKeyPressed(Keyboard::Return)){
				gameState = PlayGame;
			}
			
		}else if(gameState == PlayGame){				/// Inicia el Juego
			unicaVez =true;
			
			paleta->Update();
			bola->Choque(*paleta);
			bola->Update();
			w.clear(Color(25,25,25));
			w.draw(*paleta);
			w.draw(*bola);
			
			///no entiendo porque no puede ir aca el it++
			for(auto it = ladrillos.begin(); it!=ladrillos.end();){
				if(bola->Choque(*it)){
					contLadrillos++;
					it = ladrillos.erase(it);
				}else{
					it++;
				}
			}
			if (ladrillos.empty()){
				gameState = winMenu;
			}
			for(auto*Ladrillo : ladrillos) { 
				w.draw(*Ladrillo);
			}
			
			w.display();
			
			if(bola->Cae()){
				gameState = endMenu;
			}
			
		}else if(gameState == endMenu){					/// Perdiste
			while(unicaVez){
			contPerder++;		// no se otra forma de que cuente una unica vez, cuenta cada ciclo
			unicaVez = false;
			}
			menu.setString("--- PERDISTE!! presiona ENTER ---");
			FloatRect bounds = menu.getLocalBounds();
			menu.setOrigin(bounds.width * 0.5f, bounds.height * 0.5f);
			menu.setPosition(320.0f, 240.0f);
			
			w.clear(Color(25,25,25));
			w.draw(menu);
			w.display();
			
			if(Keyboard::isKeyPressed(Keyboard::Return)){
				for (auto* ladrillo : ladrillos) {
					delete ladrillo;
				}
				ladrillos.clear();
				
				for(int i=0;i<9;i++) { 
					for(int j=0;j<4;j++) { 
						ladrillos.push_back(new Ladrillo (35 + 70*i, 25 + 20*j));
					}
				}
				
				gameState = PlayGame;
			}
			
		}else if(gameState == winMenu){					/// Ganaste
			while(unicaVez){
			contGanar++;		// no se otra forma de que cuente una unica vez, cuenta cada ciclo			
			unicaVez = false;
			}
			menu.setString("--- GANASTE!! presiona ENTER ---");
			FloatRect bounds = menu.getLocalBounds();
			menu.setOrigin(bounds.width * 0.5f, bounds.height * 0.5f);
			menu.setPosition(320.0f, 240.0f);
			
			w.clear(Color(25,25,25));
			w.draw(menu);
			w.display();
			
			if(Keyboard::isKeyPressed(Keyboard::Return)){
				
				bola->Reinicio();
				
				for (auto* ladrillo : ladrillos) {
					delete ladrillo;
				}
				ladrillos.clear();
				
				for(int i=0;i<9;i++) { 
					for(int j=0;j<4;j++) { 
						ladrillos.push_back(new Ladrillo (35 + 70*i, 25 + 20*j));
					}
				}
				
				gameState = PlayGame;
			}
		}
	}
	
	ofstream archi("estadisticas.txt", ios::trunc);
	archi<<"partidas GANADAS: "<<contGanar<<endl;
	archi<<"partidas PERDIDAS: "<<contPerder<<endl;
	archi<<"Ladrillos Rotos Totales: "<<contLadrillos<<endl;
	archi.close();
	
	delete paleta;
	delete bola;
	for(auto* Ladrillo : ladrillos){
		delete Ladrillo;
	}

	return 0;
}

