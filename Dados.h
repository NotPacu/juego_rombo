#pragma once
#include <stdio.h>      
#include <time.h>
#include <stdlib.h>

class Dados
{

	bool debug = false;
public:
	int dados[4] = { 0,0,0,0 };
	int sumas[6] = { 0,0,0,0,0,0 };

	Dados() {
		srand(time(NULL));
	}
	int* calc_sumas();
	void tirar_dados() {
		if (!debug) {
			
			for (int i = 0; i < 4; i++) {
				dados[i] = generar_numero();
			}
			


		}
		else {

			dados[0] = 1;
			dados[1] = 1;
			dados[2] = 5;
			dados[3] = 3;
			debug = false;
		}
	}
	int generar_numero() {
		return rand() % 6 + 1;
	}
};

