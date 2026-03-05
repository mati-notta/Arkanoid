#ifndef JUEGO_H
#define JUEGO_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;
using namespace std;
class Escena;

class Juego {
public:
	Juego(Escena* scene);
	void Iniciar();
	void CambiarEscena(Escena* new_scene);
	~Juego();
private:
	Escena *m_scene, *m_proxEsc = nullptr;
	RenderWindow m_window;
};
#endif
