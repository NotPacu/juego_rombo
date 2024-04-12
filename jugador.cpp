#include <iostream>
#include <string.h>
class Jugador {
	public:
		int id;
		int puntos;
		int guardianes_restantes;
		int exploradores;
		string nombre;

		Jugador(int id, string nombre);

		int mover_ficha(int jugador_id, int movimiento1, int movimient2);
		void forzar_turno_perdido();
};

Jugador::
