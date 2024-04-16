#include <iostream>
#include <string>

class Jugador {
	public:
		int id;
		int puntos = 0;
		int guardianes_restantes = 10;
		int exploradores = 5;
		std::string nombre;

		Jugador(int id, std::string nombre);

		//int mover_ficha(int jugador_id, int movimiento1, int movimient2);
		//void forzar_turno_perdido();
};

Jugador::Jugador(int id_, std::string nombre_){
	id = id_;
	nombre = nombre_;
}



