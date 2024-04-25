#include "Jugador.h"
#include "Dados.h"

Jugador::Jugador(Tablero* tab_, Graficador* graficador_, Dados* dados_, pj_data pj_)
{
	tab = tab_;
	graficador = graficador_;
	dados = dados_;
	pj = pj_;

}

void Jugador::mover_ficha(int columna, bool capitan)
{

}

bool Jugador::validar_movimiento(int columna, bool capitan)
{

	if (capitan && fichas_pos[columna] == 1) {
		return false;
	}
	else if (fichas_pos[columna] == 2 && !capitan) {
		return false;
	}

	if ((fichas_pos[columna] != 2) && capitan && capitan_activado) {
		return false;
	}

	if ((fichas_pos[columna] == 0 || fichas_pos[columna] == 3) && exploradores == 0 && !capitan) {
		return false;
	}

	return true;
}

void Jugador::perder_turno()
{
	graficador->turno_perdido();
	exploradores = 2;
	capitan_activado = false;
	for (int i = 0; i < 11; i++) {

		fichas_pos[i] = fichas_pos_back[i];
	}
	tab->perder_turno(pj.id);
}

void Jugador::cerrar_turno()
{
	exploradores = 2;
	capitan_activado = false;
	for (int i = 0; i < 11; i++) {
		if (fichas_pos[i] != 0) {
			fichas_pos[i] = 3;
		}

		fichas_pos_back[i] = fichas_pos[i];
	}

	tab->cerrar_turno(pj.id);
}

int* Jugador::descartar_lista() {

	for (int i = 0; i < 24; i++) {
		descartes[i] = 0;
	}



	int n = 0;
	for (int i = 1; i <= 3; ++i) {
		for (int j = i + 1; j <= 6; ++j) {

			if (!tab->validar_combinacion(pj.id, dados->sumas[i - 1] - 2, dados->sumas[j - 1] - 2, i > 3, j > 3)) {

				descartes[n] = -1;
				descartes[n + 1] = -1;
				n += 2;
				continue;
			}

			if (validar_movimiento(dados->sumas[i - 1] - 2, i > 3)) {
				descartes[n] = dados->sumas[i - 1];
			}
			else {

				descartes[n] = -1;
				descartes[n + 1] = -1;

			}
			n++;
			if (validar_movimiento(dados->sumas[j - 1] - 2, j > 3)) {
				descartes[n] = dados->sumas[j - 1];
			}
			else {

				descartes[n] = -1;
				descartes[n - 1] = -1;

				//descartes[n] =-descartes[n];
				//descartes[n - 1] = -descartes[n - 1];

			}

			if (descartes[n] != 1) {
				if ((fichas_pos[descartes[n] - 2] == 0 || fichas_pos[descartes[n] - 2] == 3) && (fichas_pos[descartes[n - 1] - 2] == 0 || fichas_pos[descartes[n - 1] - 2] == 3)) {
					if (exploradores <= 1) {
						if (i <= 3 && j <= 3) {
							descartes[n] = -1;
							descartes[n - 1] = -1;
							//std::cout<<"::"<<descartes[n]<<descartes[n - 1]<<std::endl;
						}
					}
				}
			}
			n++;

		}

	}

	return descartes;
}

int Jugador::turno() {
	int par = 0;
	int mov1, mov2 = 0;
	bool cap1 = false;
	bool cap2 = false;
	graficador->limpiar_pantalla();
	graficador->print_completo(u8"Turno del jugador " + std::to_string(pj.id), 83, 14, colores[(pj.id - 1) * 3] * 4.5, colores[(pj.id - 1) * 3 + 1] * 4.5
		, colores[(pj.id - 1) * 3 + 2] * 4.5);

	graficador->graficar_tablero(tab->retornar_tablero(), colores[(pj.id - 1) * 3], colores[(pj.id - 1) * 3 + 1], colores[(pj.id - 1) * 3 + 2]);

	dados->tirar_dados();
	dados->calc_sumas();

	graficador->graficar_dados(*dados);
	descartar_lista();

	par = graficador->selecionar_combinacion(descartes);


	if (par == -1) {

		perder_turno();
		return -1;
	}


	int n = 0;
	for (int i = 1; i <= 3; ++i) {
		for (int j = i + 1; j <= 6; ++j) {
			if (n == par) {

				mov1 = descartes[n];
				mov2 = descartes[n + 1];
				cap1 = i > 3;
				cap2 = j > 3;
			}
			n += 2;
		}
	}

	if (cap1 || cap2) {
		capitan_activado = true;
	}

	if (cap2) {
		fichas_pos[mov2 - 2] = 2;
	}else {

		if (fichas_pos[mov2 - 2] == 0 || fichas_pos[mov2 - 2] == 3) {
			exploradores--;
		}

		fichas_pos[mov2 - 2] = 1;
	}

	if (cap1) {
		fichas_pos[mov1 - 2] = 2;
	}else {
		if (fichas_pos[mov1 - 2] == 0 || fichas_pos[mov1 - 2] == 3) {
			exploradores--;
		}

		fichas_pos[mov1 - 2] = 1;
	}



	if (!cap1 && !cap2) {
		if (mov1 == mov2) {
			exploradores++;
		}
	}

	int p1 = tab->mover_ficha(pj.id, mov1 - 2, cap1);
	int p2 = tab->mover_ficha(pj.id, mov2 - 2, cap2);

	if (p1 == 1) {
		if (cap1) {
			capitan_activado = false;
		}
		else {
			//exploradores++;
		}
	}

	if (p2 == 1) {
		if (cap2) {
			capitan_activado = false;
		}
		else {
			//exploradores++;
		}
	}


	std::cout << "exploradores: " << exploradores << std::endl;
	std::cout << "puntos: " << puntos << std::endl;
	graficador->graficar_tablero(tab->retornar_tablero(), colores[(pj.id - 1) * 3], colores[(pj.id - 1) * 3 + 1], colores[(pj.id - 1) * 3 + 2]);
	
	int slc = graficador->selecionar_accion();


	if (puntos >= 5) {
		graficador->limpiar_pantalla();
		graficador->pantalla_win(pj.nombre);
		std::cin.get();
		return 1;
	}

	if (slc == 0) {
		turno();
		return -1;
	}
	if (slc == 1) {
		cerrar_turno();
		return -1;
	}

	if (slc == 2) {
		cerrar_turno();
		return 2;
	}
}


void Jugador::reload() {
	int** tab_ = tab->retornar_tablero();


	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < tab->size[i]; j++) {
			if (tab_[i][j] == pj.id + 8) {
				fichas_pos[i] = 3;
				break;
			}
		}
	}
}
