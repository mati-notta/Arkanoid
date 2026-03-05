#include "Estadisticas.h"
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

Estadisticas::Estadisticas() {

}

vector<Jugador> Estadisticas::Leer(){
	vector<Jugador> lista;
	ifstream archi("estadistica.dat", ios::binary);
	Jugador jug;
	
	while(archi.read(reinterpret_cast<char*>(&jug), sizeof(Jugador))){
		lista.push_back(jug);
	}
	archi.close();
	return lista;
}

void Estadisticas::GuardarJugador(string nom, int puntaje){
	vector<Jugador>lista = Leer();
	Jugador nuevoJugador;
	
	nuevoJugador.puntuacion = puntaje;
	strncpy(nuevoJugador.nombre, nom.c_str(), 15);
	nuevoJugador.nombre[15] = '\0';		///es el enter
	
	lista.push_back(nuevoJugador);
	OrdenarLista(lista);
	
	ofstream archi("estadistica.dat", ios::binary | ios::trunc);
	for (auto &registro : lista){
		archi.write(reinterpret_cast<char*> (&registro), sizeof(Jugador));
	}
	archi.close();
}

void Estadisticas::OrdenarLista(vector<Jugador>&lista){
	sort(lista.begin(), lista.end(), CompararJugador);
	if(lista.size()>10) lista.resize(10);
}

bool Estadisticas::CompararJugador(Jugador &a, Jugador &b){
	return a.puntuacion > b.puntuacion;
}
