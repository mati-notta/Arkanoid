#include "Juego.h"
#include "Menu.h"

int main(int argc, char *argv[]){
	Juego game(new Menu);
	game.Iniciar();
	return 0;
}
//			while(unicaVez){
//				contGanar++;		// no se otra forma de que cuente una unica vez, cuenta cada ciclo			
//				unicaVez = false;

//			menu.setString("--- GANASTE!! presiona ENTER ---");
//			FloatRect bounds = menu.getLocalBounds();
//			menu.setOrigin(bounds.width * 0.5f, bounds.height * 0.5f);
//			menu.setPosition(320.0f, 240.0f);

//	ofstream archi("estadisticas.txt", ios::trunc);
//	archi<<"partidas GANADAS: "<<contGanar<<endl;
//	archi<<"partidas PERDIDAS: "<<contPerder<<endl;
//	archi<<"Ladrillos Rotos Totales: "<<contLadrillos<<endl;
//	archi.close();

	
