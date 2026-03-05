#include "Colision.h"

Colision::Colision() {
	
}

Vector2f Colision::CalChoque(FloatRect bola, FloatRect ladrillo){

	if(!bola.intersects(ladrillo)) return {0.f, 0.f};
	
	if (bola.left+bola.width < ladrillo.left) return {0,0}; 			// b1 esta completamente a la izquierda de b2
	if (bola.left > ladrillo.left + ladrillo.width) return {0,0}; 		// b1 esta completamente a la derecha de b2
	if (bola.top + bola.height < ladrillo.top) return {0,0}; 			// b1 esta completamente arriba de b2
	if (bola.top > ladrillo.top + ladrillo.height) return {0,0}; 		// b1 esta completamente abajo de b2
	float dx, dy;
	if (bola.left + bola.width/2 < ladrillo.left + ladrillo.width/2) 	// comparo los centros para decir izquierda/derecha
		dx = ladrillo.left - (bola.left + bola.width); 					// si esta a la izquierda, dx da negativo
	else
		dx = (ladrillo.left + ladrillo.width) - bola.left; 				// si esta a la derecha, dx da positivo
	if (bola.top + ladrillo.height/2 < bola.top + ladrillo.height/2) 	// comparo los centros para decir arriba/abajo
		dy = ladrillo.top - (bola.top + bola.height); 					// si esta arriba, dy da negativo
	else
		dy = (ladrillo.top + ladrillo.height) - bola.top; 				// si esta abajo, dy da positivo
	return {dx, dy};


}

Colision::~Colision(){
	
}
