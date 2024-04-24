#pragma once
#include <string>
#include <iostream>
#include "tablero.h"
#include "Dados.h"
#include <vector>
#include <limits>

#undef max
class Graficador
{
private:
	int size[11] = { 3,5,7,9,11,13,11,9,7,5,3 };

public:
	Graficador();
	~Graficador();

	void graficar_dados(Dados d);
	void graficar_tablero(int* tab[11], int r, int g, int b);
	std::string traducir_ficha(int id);
	void color_auto(int ficha, std::string text);
	void mostrar_combinaciones(int* cmbs, int selec);
	int selecionar_combinacion(int* cmbs);
	int selecionar_accion();
	void turno_perdido();
	bool menu_principal();
	void pantalla_win(std::string nombre) {

		std::string arte_ascii = R"(
								 ____
						  /^\   / -- )
						 / | \ (____/
						/ | | \ / /
					   /_|_|_|_/ /
						|     / /
		 __    __    __ |    / /__    __    __
		[  ]__[  ]__[  ].   / /[  ]__[  ]__[  ]
		|__            ____/ /___           __|
		   |          / .------  )         |
		   |         / /        /          |
		   |        / /        /           |
		~~~~~~~~~~~~-----------~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			)";


		imprimir_cyan(arte_ascii);

		imprimir_amarillo("\n\nganó: " + nombre);
	}

	int solicitarNumeroJugadores() {
		int numJugadores;
		bool entradaValida;

		do {
			entradaValida = true; // Inicializar la bandera de entrada válida

			std::cout << "¿Cuántos jugadores serán? (2 o 4): ";

			// Intentar leer el número de jugadores
			if (!(std::cin >> numJugadores)) {
				// Hubo un error al leer un entero
				std::cout << "Error: entrada inválida. Intente de nuevo.\n";
				entradaValida = false;
				// Limpiar el estado fallido de std::cin
				std::cin.clear();
				// Descartar el resto de la entrada incorrecta en el búfer
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (numJugadores != 2 && numJugadores != 4) {
				// El número de jugadores no es válido
				std::cout << "Por favor, seleccione 2 o 4 jugadores.\n";
				entradaValida = false;
			}

		} while (!entradaValida);

		return numJugadores;
	}

	std::vector<std::string> solicitarNombresJugadores(int numJugadores) {
		std::vector<std::string> nombres;  // Vector para almacenar los nombres de los jugadores

		std::cout << "\n";

		for (int i = 0; i < numJugadores; i++) {
			std::string nombre;
			std::cout << "Nombre del jugador " << i + 1 << ": ";
			std::cin >> nombre;  // Lee el nombre del jugador
			nombres.push_back(nombre);  // Agrega el nombre al vector
		}

		std::cout << "\n";

		return nombres;  // Devuelve el vector con los nombres
	}

	void print_completo(const std::string& text, int x, int y, int r, int g, int b) {

		std::string colorCode = "\033[" + std::to_string(y) + ";" + std::to_string(x) + "H";  // Posiciona el cursor
		colorCode += "\033[38;2;" + std::to_string(r % 257) + ";" + std::to_string(g % 257) + ";" + std::to_string(b % 257) + "m";  // Establece el color RGB


		std::cout << colorCode << text << "\033[0m";
	}
	void Dado_to_ascii(int num, int x, int y, int r, int g, int b);
	void imprimir_desde(std::string texto, int x, int y) {
		printf("\x1b[%d;%df", y, x);
		std::cout << texto;
	}
	void imprimir_rojo(std::string texto) {
		std::cout << "\033[31m" << texto << "\033[1m";
	}
	void imprimir_amarillo(std::string texto) {
		std::cout << "\033[33m" << texto << "\033[0m";
	}
	void imprimir_verde_claro(std::string texto) {
		std::cout << "\033[92m" << texto << "\033[1m";
	}
	void imprimir_verde(std::string texto) {
		std::cout << "\033[32m" << texto << "\033[1m";
	}
	void imprimir_azul(std::string texto) {
		std::cout << "\033[34m" << texto << "\033[1m";
	}
	void imprimir_magenta(std::string texto) {
		std::cout << "\033[35m" << texto << "\033[1m";
	}
	void imprimir_cyan(std::string texto) {
		std::cout << "\033[36m" << texto << "\033[1m";
	}
	void imprimir_blanco(std::string texto) {
		std::cout << "\033[37m" << texto << "\033[1m";
	}
	void imprimir_negro(std::string texto) {
		std::cout << "\033[30m" << texto << "\033[0m";
	}
	void imprimir_blanco_brillante(std::string texto) {
		std::cout << "\033[87m" << texto << "\033[1m";
	}
	void limpiar_pantalla() {
		std::cout << "\033[2J\033[1;1H";
	}
	void color_de_fondo(int r, int g, int b) {
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
			std::cerr << "Error: Los componentes RGB deben estar en el rango de 0 a 255.\n";
			return;
		}
		std::cout << "\x1B[48;2;" << r << ";" << g << ";" << b << "m";
	}
	void reset() {
		std::cout << "\033[0m";
	}
};
