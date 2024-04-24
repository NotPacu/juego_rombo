#include "Graficador.h"
#include <stdio.h>
#include <locale>
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>

int traducir_codigo(int codigo) {
	int c = codigo % 4;
	if (codigo == 0) { return 0; }

	if (c == 0	) { c = 4; }
	return c;
}

Graficador::Graficador() {

}

Graficador::~Graficador() {

}

void Graficador::graficar_dados(Dados d)
{
	Dado_to_ascii(d.dados[0], 30, 3, 245, 194, 66);
	Dado_to_ascii(d.dados[1], 30 + 10 * 1, 3, 3, 186, 252);
	for (int i = 0; i < 2; i++) {
		Dado_to_ascii(d.dados[i + 2], 30 + 10 * i, 8, 3, 186, 252);
	}
}

void Graficador::graficar_tablero(int* tab[11], int r, int g, int b) {

	imprimir_desde("", 0, 0);
	color_de_fondo(r, g, b);
	imprimir_blanco_brillante(u8"┌");
	for (int i = 0; i < 11 * 2; i++) {
		imprimir_blanco_brillante(u8"─");
	}
	imprimir_blanco_brillante(u8"┐\n");
	for (int j = 13; j >= 0; j--) {
		imprimir_blanco_brillante(u8"│");
		for (int i = 0; i < 11; i++) {
			if (j < size[i]) {
				//std::cout<< traducir_ficha(tab[i][j]) << " ";

				color_auto(tab[i][j], traducir_ficha(tab[i][j]));
				imprimir_blanco(" ");
			}
			else {
				imprimir_blanco("  ");
			}
		}
		imprimir_blanco_brillante(u8"│\n");
	}
	imprimir_blanco_brillante(u8"│");
	imprimir_blanco_brillante("2 ");
	for (int i = 1; i < 10; i++) {

		imprimir_blanco_brillante("  ");
	}
	imprimir_blanco_brillante("12");
	imprimir_blanco_brillante(u8"│\n");
	imprimir_blanco_brillante(u8"└");
	for (int i = 0; i < 11 * 2; i++) {
		imprimir_blanco_brillante(u8"─");
	}
	imprimir_blanco_brillante(u8"┘\n");

	reset();


}

std::string Graficador::traducir_ficha(int id)
{
	switch (id) {
	case 0:
		return u8"■";
	case 1:
	case 2:
	case 3:
	case 4:
		return "X";
	case 5:
	case 6:
	case 7:
	case 8:
		return "T";
	case 9:
	case 10:
	case 11:
	case 12:
		return u8"╬";
	}

}

void Graficador::color_auto(int ficha, std::string text)
{
	if (ficha == 0) {
		imprimir_blanco(text);
		return;
	}
	switch (traducir_codigo(ficha))
	{
	case 1:
		imprimir_rojo(text);
		break;
	case 2:
		imprimir_verde(text);
		break;
	case 3:
		imprimir_azul(text);
		break;
	case 4:
		imprimir_magenta(text);
		break;
	default:
		imprimir_blanco(text);
		break;
	};
}
/*
┌───────┐
│ ■     │
│   ■   │
│     ■ │
└───────┘

┌───────┐
│ ■   ■ │
│ ■   ■ │
│ ■   ■ │
└───────┘
*/
void Graficador::Dado_to_ascii(int num, int x, int y, int r, int g, int b)
{
	std::cout << ("\033[s");

	std::cout << "\x1b[38;2;" << r << ";" << g << ";" << b << "m";
	if (num == 1) {
		imprimir_desde(u8"┌───────┐\n", x, y);
		imprimir_desde(u8"│       │\n", x, y + 1);
		imprimir_desde(u8"│   ■   │\n", x, y + 2);
		imprimir_desde(u8"│       │\n", x, y + 3);
		imprimir_desde(u8"└───────┘\n", x, y + 4);
	}
	else if (num == 2) {
		imprimir_desde(u8"┌───────┐\n", x, y);
		imprimir_desde(u8"│   ■   │\n", x, y + 1);
		imprimir_desde(u8"│       │\n", x, y + 2);
		imprimir_desde(u8"│   ■   │\n", x, y + 3);
		imprimir_desde(u8"└───────┘\n", x, y + 4);
	}
	else if (num == 3) {
		imprimir_desde(u8"┌───────┐\n", x, y);
		imprimir_desde(u8"│ ■     │\n", x, y + 1);
		imprimir_desde(u8"│   ■   │\n", x, y + 2);
		imprimir_desde(u8"│     ■ │\n", x, y + 3);
		imprimir_desde(u8"└───────┘\n", x, y + 4);
	}
	else if (num == 4) {
		imprimir_desde(u8"┌───────┐\n", x, y);
		imprimir_desde(u8"│ ■   ■ │\n", x, y + 1);
		imprimir_desde(u8"│       │\n", x, y + 2);
		imprimir_desde(u8"│ ■   ■ │\n", x, y + 3);
		imprimir_desde(u8"└───────┘\n", x, y + 4);
	}
	else if (num == 5) {
		imprimir_desde(u8"┌───────┐\n", x, y);
		imprimir_desde(u8"│ ■   ■ │\n", x, y + 1);
		imprimir_desde(u8"│   ■   │\n", x, y + 2);
		imprimir_desde(u8"│ ■   ■ │\n", x, y + 3);
		imprimir_desde(u8"└───────┘\n", x, y + 4);
	}
	else if (num == 6) {
		imprimir_desde(u8"┌───────┐\n", x, y);
		imprimir_desde(u8"│ ■   ■ │\n", x, y + 1);
		imprimir_desde(u8"│ ■   ■ │\n", x, y + 2);
		imprimir_desde(u8"│ ■   ■ │\n", x, y + 3);
		imprimir_desde(u8"└───────┘\n", x, y + 4);
	}

	printf("\033[u");



}

void Graficador::mostrar_combinaciones(int* combs, int selec) {

	std::cout << ("\033[s");

	print_completo("----------------", 65, 2, 3, 198, 252);

	print_completo(u8"■ : Capitan", 83, 3, 245, 194, 66);
	print_completo(u8"■ : Explorador", 83, 4, 3, 186, 252);
	print_completo(u8"T : Capitan", 83, 6, 107, 3, 252);
	print_completo(u8"X : Explorador", 83, 7, 107, 3, 252);
	print_completo(u8"╬ : Guardian", 83, 8, 107, 3, 252);


	print_completo(u8"W : Para subir", 83, 10, 255, 148, 87);
	print_completo(u8"S : Para bajar", 83, 11, 255, 148, 87);
	print_completo(u8"Enter : Para seleccionar", 83, 12, 255, 148, 87);


	




	int n = 0;
	int pading = 0;
	for (int i = 1; i <= 3; ++i) {
		for (int j = i + 1; j <= 6; ++j) {
			if (n == selec) {
				if (combs[n] == -1) {
					selec += 2;
				}
				else {
					color_de_fondo(120, 120, 120);
				}
			}
			if (combs[n] == -1) {
				n += 2;
				continue;
			}
			if (i > 3) {
				if (combs[n] > 9) {
					print_completo("[  " + std::to_string(combs[n]) + " ]", 65, 3 + pading / 2, 245, 194, 66);
				}
				else {

					print_completo("[  " + std::to_string(combs[n]) + "  ]", 65, 3 + pading / 2, 245, 194, 66);
				}

			}
			else {
				if (combs[n] > 9) {

					print_completo("[  " + std::to_string(combs[n]) + " ]", 65, 3 + pading / 2, 3, 186, 252);
				}
				else {

					print_completo("[  " + std::to_string(combs[n]) + "  ]", 65, 3 + pading / 2, 3, 186, 252);
				}
			}
			n++;
			pading++;

			if (n - 1 == selec) {
				color_de_fondo(120, 120, 120);
			}
			std::cout << "  ";

			if (j > 3) {
				if (combs[n] > 9) {
					print_completo("[  " + std::to_string(combs[n]) + " ]", 74, 3 + pading / 2, 245, 194, 66);
				}
				else {

					print_completo("[  " + std::to_string(combs[n]) + "  ]", 74, 3 + pading / 2, 245, 194, 66);
				}
			}
			else {
				if (combs[n] > 9) {
					print_completo("[  " + std::to_string(combs[n]) + " ]", 74, 3 + pading / 2, 3, 186, 252);
				}
				else {
					print_completo("[  " + std::to_string(combs[n]) + "  ]", 74, 3 + pading / 2, 3, 186, 252);

				}
			}
			n++;
			pading++;


			if (selec == n - 2) {
				reset();
			}
		}

	}
	print_completo("----------------", 65, 15, 3, 198, 252);
	printf("\033[u");
}

int Graficador::selecionar_combinacion(int* cmbs)
{
	int selec = 0;
	bool tiene_opciones = false;
	for (int i = 0; i < 12; i++) {
		//std::cout<<cmbs[i * 2] << " " << cmbs[i * 2 + 1] << std::endl;
		if (cmbs[i * 2] != -1) {
			tiene_opciones = true;
		}
	}



	mostrar_combinaciones(cmbs, selec);
	if (!tiene_opciones) {
		return -1;
	}
	while (true) {
		selec += 2;

		if (selec > 22) {
			selec = 0;
		}
		if (cmbs[selec] != -1) {
			break;
		}

	}
	mostrar_combinaciones(cmbs, selec);

	while (true) {
		unsigned char key = _getch();



		switch ((int)key)
		{
		case 119:
			while (true) {
				selec -= 2;
				if (selec < 0) {
					selec = 22;
				}
				if (cmbs[selec] != -1) {
					break;
				}
			}
			break;
		case 115:
			while (true) {
				selec += 2;

				if (selec > 22) {
					selec = 0;
				}
				if (cmbs[selec] != -1) {
					break;
				}

			}
			break;

		case 13:
			return selec;
		}

		mostrar_combinaciones(cmbs, selec);
	}

	return 0;
}

int Graficador::selecionar_accion()
{
	print_completo("::Seguir tirando ", 1, 20, 149, 168, 252);
	print_completo("::Terminar turno", 1, 21, 149, 168, 252);
	print_completo("::Salir", 1, 22, 149, 168, 252);
	print_completo("::(Salir se cierra turno y se guarda)", 1, 24, 149, 168, 252);

	int selec = 0;
	print_completo(" <- ", 24, selec + 20, 255, 255, 255);
	while (true) {
		unsigned char key = _getch();



		switch ((int)key) {
		case 115:
			selec++;
			if (selec >= 3) {
				selec = 0;
			}
			break;
		case 119:
			selec--;
			if (selec < 0) {
				selec = 2;
			}
			break;
		case 13:
			return selec;

		}

		print_completo("   ", 24, 20, 255, 255, 255);
		print_completo("   ", 24, 21, 255, 255, 255);
		print_completo("   ", 24, 22, 255, 255, 255);

		print_completo(" <- ", 24, selec + 20, 255, 255, 255);
	}

}

void Graficador::turno_perdido()
{
	imprimir_amarillo("No tiene jugadas posibles, pierde el turno");
	imprimir_blanco_brillante(" Presione una tecla para continuar");
	_getch();
}

bool Graficador::menu_principal()
{

	bool selec = false;
	imprimir_blanco_brillante(":::::::::Bienvenido al juego del rombo:::::::::\n");
	imprimir_blanco_brillante("::Desea crear una nueva partida \n");
	imprimir_blanco_brillante("::Cargar una anterior\n");
	print_completo(" <- ", 44, selec + 2, 250, 188, 30);
	while (true) {
		unsigned char key = _getch();



		switch ((int)key) {
		case 115:
			selec = !selec;

			break;
		case 119:
			selec = !selec;
			break;
		case 13:
			return selec;

		}

		print_completo("   ", 44, 2, 255, 255, 255);
		print_completo("   ", 44, 3, 255, 255, 255);


		print_completo(" <- ", 44, selec + 2, 250, 188, 30);
	}

	return false;
}


