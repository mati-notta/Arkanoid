#include "Juego.h"
#include "Menu.h"

int main(int argc, char *argv[]){
	Juego game(new Menu);
	game.Iniciar();
	return 0;
}
