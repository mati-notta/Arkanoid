#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

#include <vector>
#include <string>
using namespace std;
//using namespace sf;

struct Jugador{
	char nombre[16];
	int puntuacion;
};

class Estadisticas {
public:
	Estadisticas();
	void GuardarJugador(string nom, int puntaje);
	void OrdenarLista(vector<Jugador>&lista);
	static bool CompararJugador(Jugador &a, Jugador &b);
	
	vector<Jugador> Leer();
private:
	
};

#endif

