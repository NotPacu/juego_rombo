#include "Dados.h"



int* Dados::calc_sumas() {
	
	sumas[5] = dados[0] + dados[1];
	sumas[4] = dados[0] + dados[2];
	sumas[3] = dados[0] + dados[3];
	sumas[2] = dados[1] + dados[2];
	sumas[1] = dados[1] + dados[3];
	sumas[0] = dados[2] + dados[3];
	return sumas;
}