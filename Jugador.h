#pragma once
#include <string>
#include "tablero.h"
#include "Graficador.h"
#include "Dados.h"

struct pj_data
{
	std::string nombre;
	int nombre_len;
	int id;
};

class Jugador
{
	// 1 exp , 2 cap , 3 guard 
	int colores[12] = { 40,0,0,  0,40,0, 0,0,40 , 40, 18, 54 };
	int exploradores = 2;
	int guardianes = 10;
	bool capitan_activado = false;
	int fichas_pos[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
	int fichas_pos_back[11] = { 0,0,0,0,0,0,0,0,0,0,0 };

	int descartes[24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	int puntos = 0;
	pj_data pj;
	
	Tablero* tab;
	Graficador* graficador;
	Dados* dados;


public:
	Jugador(Tablero* tab_,Graficador* graficador_,Dados* dados_,pj_data pj_);
	int turno();
	void mover_ficha(int columna,bool capitan);
	bool validar_movimiento(int columna, bool capitan);
	void perder_turno();
	void cerrar_turno();
	int* descartar_lista();
	void reload();
};

