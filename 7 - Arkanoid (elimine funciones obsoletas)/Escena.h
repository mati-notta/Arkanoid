#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;
using namespace sf;
class Juego;

class Escena {
public:
	Escena();
	virtual void Update(Juego &game) = 0;
	virtual void Draw(RenderWindow &window) = 0;
	virtual void ProcesarEvento(const Event &e) {}
private:
};
#endif
