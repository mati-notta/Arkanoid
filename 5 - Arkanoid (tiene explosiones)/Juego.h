#ifndef JUEGO_H
#define JUEGO_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>

using namespace sf;
using namespace std;
class Escena;

class Juego {
public:
	Juego(Escena* scene);
	void Iniciar();
	void CambiarEscena(Escena* new_scene);
	void GuardarEstilo(vector<Color>colores);
	vector<Color> verEstilo();
	~Juego();
private:
	Escena *m_scene, *m_proxEsc = nullptr;
	RenderWindow m_window;
	vector<Color> m_coloresActuales;
};
#endif
