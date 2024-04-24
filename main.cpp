
#include <iostream>
#include <windows.h>
#include "tablero.h"
#include "Graficador.h"
#include <locale>
#include "Dados.h"
#include "Jugador.h"
#include "SaveAndLoader.h"



bool EnableVTMode()
{
	// Set output mode to handle virtual terminal sequences
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode))
	{
		return false;
	}

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	return SetConsoleMode(hOut, dwMode) != 0;
}

int main() {
	EnableVTMode();
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	std::cout << "\x1B[=19h";
	int n_jugadores = 0;
	int turno = 0;
	std::vector<std::string> nombres;
	Tablero t;
	Graficador g;
	Dados d;
	SaveAndLoader sv;
	pj_data datas[4];


	std::vector<Jugador> jugadores;



	g.limpiar_pantalla();
	if (g.menu_principal()) {

		try {

			sv.load("save.bin", &turno, &t, &nombres);
		}
		catch (std::exception& e) {
			g.limpiar_pantalla();
			g.imprimir_amarillo("No se encontro una partida guardada");
			return 0;

		}

		for (int i = 0; i < nombres.size(); i++) {
			datas[i].nombre = nombres[i];
			datas[i].nombre_len = nombres[i].size();
			datas[i].id = i + 1;
			jugadores.push_back(Jugador(&t, &g, &d, datas[i]));
		}


		
		for (int i = 0; i < n_jugadores; i++) {
			jugadores[i].reload();
		}

	}
	else {
		g.limpiar_pantalla();
		n_jugadores = g.solicitarNumeroJugadores();
		g.limpiar_pantalla();
		nombres = g.solicitarNombresJugadores(n_jugadores);



		for (int i = 0; i < n_jugadores; i++) {
			datas[i].nombre = nombres[i];
			datas[i].nombre_len = nombres[i].size();
			datas[i].id = i + 1;
			jugadores.push_back(Jugador(&t, &g, &d, datas[i]));
		}
	}





	

	while (true) {

		for (int i = turno; i < nombres.size(); i++) {

			int hp = jugadores[i].turno();

			if (hp == 2) {
				sv.save("save.bin", i + 1, &t, nombres);
				return 0;
			}

			if (hp != -1) {
				return hp;
			}


		}
		turno = 0;
	}




}