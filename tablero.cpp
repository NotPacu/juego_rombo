#include "tablero.h"
#include <iostream>

Tablero::Tablero() {
	for (int i = 0; i < 11; i++) {
		tab[i] = new int[size[i]];
		tab_back[i] = new int[size[i]];
		for (int j = 0; j < size[i]; j++) {
			tab[i][j] = 0;
			tab_back[i][j] = 0;
		}
	}
	for (int i = 0; i < 44; i++) {
		casillas_bloqueadas[i] = 0;
	}
}

Tablero::~Tablero() {
	for (int i = 0; i < 11; i++) {
		delete tab[i];
	}
}

int Tablero::traducir_codigo(int codigo) {
	int c = codigo % 4;
	if (codigo == 0) { return 4; }
	return c;
}

int Tablero::tiene_capitan(int jugador_id, int columna, bool guardianes) {
	for (int i = 0; i < size[columna]; i++) {
		if (tab[columna][i] == jugador_id + 4 && !guardianes) {
			return i;
		}

		if ((tab[columna][i] == jugador_id+4 || tab[columna][i] == jugador_id+8) && guardianes && tab[columna][i] != 0) {
			return i;
		}
	}
	return -1;
}

int Tablero::tiene_explorador(int jugador_id, int columna, bool guardianes) {
	for (int i = 0; i < size[columna]; i++) {

		if (tab[columna][i] == jugador_id && !guardianes) {
			return i;
		}

		if ((tab[columna][i] == jugador_id || tab[columna][i] == jugador_id + 8) && guardianes && tab[columna][i] != 0) {
			return i;
		}
	}
	return -1;
}



void Tablero::imprimir_tablero() {

	/*
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < size[i]; j++) {

			std::cout<<tab[i][j]<<" ";
		}

		std::cout<<"\n";
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			std::cout << tab[j][i] << " ";

		}
		std::cout<<"\n";
	}

	for (int j = 0; j < 13; ++j) {
		for (int i = 11 - 1; i >= 0; --i) {
			if (j < size[i]) {
				std::cout << tab[i][j] << " ";
			}
			else {
				std::cout << "  "; // Espacio en blanco si no hay elemento
			}
		}
		std::cout << "\n";
	}

	*/

	for (int j = 13; j >= 0; j--) {
		for (int i = 0; i < 11; i++) {
			if (j < size[i]) {
				std::cout << tab[i][j] << " ";
			}
			else {
				std::cout << "  ";
			}
		}
		std::cout << "\n";
	}

}

bool Tablero::columna_bloqueada(int jugador_id, int columna) {
	if (casillas_bloqueadas[columna + 11 * (jugador_id - 1)] == 1) {
		return true;
	}
	return false;
}

int Tablero::mover_ficha(int jugador_id, int columna, bool cap) {

	if (cap) {
		int pos = tiene_capitan(jugador_id, columna, true);
		if (pos == -1) {
			for (int i = 0; i < size[columna]; i++) {
				if (tab[columna][i] == 0 && i == size[columna] - 1) {
					return 1;
				}
				if (tab[columna][i] == 0) {
					tab[columna][i] = jugador_id + 4;
					return 0;
				}
			}
			return -666;
		}
		else {
			for (int i = pos + 1; i < size[columna]; i++) {
				if (tab[columna][i] == 0 && i == size[columna] - 1) {
					tab[columna][pos] = 0;
					return 1;
				}
				if (tab[columna][i] == 0) {
					tab[columna][pos] = 0;
					tab[columna][i] = jugador_id+4;
					return 0;
				}
			}
			return -666;
		}
	}
	else {
		int pos = tiene_explorador(jugador_id, columna, true);
		if (pos == -1) {
			for (int i = 0; i < size[columna]; i++) {
				if (tab[columna][i] == 0 && i == size[columna] - 1) {
					return 1;
				}
				if (tab[columna][i] == 0) {
					tab[columna][i] = jugador_id;
					return 0;
				}
			}
			return -666;
		}
		else {
			for (int i = pos + 1; i < size[columna]; i++) {
				if (tab[columna][i] == 0 && i == size[columna] - 1) {
					tab[columna][pos] = 0;
					return 1;
				}
				if (tab[columna][i] == 0) {
					tab[columna][pos] = 0;
					tab[columna][i] = jugador_id;
					return 0;
				}
			}
			return -666;
		}

	}

}

bool Tablero::validar_combinacion(int jugador_id, int columna, int columna2, bool capitan, bool capitan2) {




	if ((capitan && capitan2) && (columna != columna2)) {
		return false;
	}
	if ((columna == columna2) && (capitan != capitan2)) {
		return false;
	}

	if (columna_bloqueada(jugador_id, columna) || columna_bloqueada(jugador_id, columna2)) {
		return false;
	}


	if (capitan) {

		if (tiene_explorador(jugador_id, columna, false) != -1) {
			return false;
		}
	}
	else {

		if (tiene_capitan(jugador_id, columna, false) != -1) {
			return false;
		}
	}

	if (capitan2) {

		if (tiene_explorador(jugador_id, columna2, false) != -1) {
			return false;
		}
	}
	else {

		if (tiene_capitan(jugador_id, columna2, false) != -1) {
			return false;
		}
	}

	return true;

}

void Tablero::forzar_cambio(int valor, int fila, int columna) {
	Tablero::tab[fila][columna] = valor;
}

void Tablero::eliminar_guardian(int jugador_id, int columna) {
	for (int i = 0; i < size[columna]; i++) {
		if (tab[columna][i] == jugador_id + 8) {
			tab[columna][i] = 0;
			tab_back[columna][i] = 0;
			return;
		}
	}
}

int* Tablero::cantidad_fichas(int jugador_id) {


	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < size[i]; j++) {
			if (traducir_codigo(tab[i][j]) == jugador_id) {
				if (tab[i][j] == jugador_id) {
					cantidades[0]++;
					break;
				}
				if (tab[i][j] == jugador_id + 4) {
					cantidades[1]++;
					break;
				}
				if (tab[i][j] == jugador_id + 8) {
					cantidades[2]++;
				}
			}
		}
	}
	return cantidades;
}

void Tablero::perder_turno(int jugador_id)
{
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < size[i]; j++) {
			tab[i][j] = tab_back[i][j];
		}
	}
}

void Tablero::cerrar_turno(int jugador_id)
{
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < size[i]; j++) {
			if (traducir_codigo(tab[i][j]) == jugador_id && tab[i][j] != 0) {

				tab[i][j] = jugador_id+8;
			}
				tab_back[i][j] = tab[i][j];
		}
	}
}



int** Tablero::retornar_tablero() {

	return tab;
}
