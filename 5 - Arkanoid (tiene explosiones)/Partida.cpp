#include "Partida.h"
#include "Paleta.h"
#include "Bola.h"
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
#include "Juego.h"
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <cmath>

using namespace sf;
using namespace std;

Partida::Partida(vector<Color> estilo) {
	settings.antialiasingLevel = 16;
	paleta = new Paleta();
	bola = new Bola();
	contLadrillos = contGanar = contPerder = 0;
	fondo = estilo[0];
	
	for(int i=0;i<10;i++) { 
		for(int j=0;j<4;j++) { 
			Ladrillo ladri(41 + 82*i, 25 + 25*j);
			ladri.Colorear(estilo[1], estilo[2], estilo[3]);
			ladrillos.push_back(ladri);
		}
	}
}

void Partida::Update(Juego &game){
	m_estilo = game.verEstilo();
	
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
///																			Particulas			
			midLadrillo = {it->getPos().left + it->getPos().width/2, it->getPos().top + it->getPos().height/2};
			for(int i=0;i<15;i++) { 
				Color c_particula;
				if(it->VerVidas() > 0) c_particula = m_estilo[it->VerVidas()];
				particulas.push_back(Explosion(midLadrillo, c_particula));
			}
			
			it->ModVidas();
			it->Colorear(m_estilo[1], m_estilo[2], m_estilo[3]);
			
			if(it->VerVidas() <=0){
				contLadrillos++;
				it = ladrillos.erase(it);
			}else{
				it++;
			}
		}else{
			it++;
		}
///																			Elimina particulas
		for(auto it = particulas.begin(); it!=particulas.end();) { 
			it->Update();
			if(it->Fin()){
				it = particulas.erase(it);
			}else{
				it++;
			}
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
			Ladrillo ladri(41 + 82*i, 25 + 25*j);
			ladri.Colorear(m_estilo[1], m_estilo[2], m_estilo[3]);
			ladrillos.push_back(ladri);
		}
	}
}

void Partida::Draw(RenderWindow &window){
	window.clear(fondo);
	paleta->Draw(window);
	bola->Draw(window);
	
	for(auto &Ladrillo : ladrillos) { 
		Ladrillo.Draw(window);
	}
	for(auto &partis : particulas){
		partis.Draw(window);
	}
}

Partida::~Partida(){
	delete paleta;
	delete bola;
}
