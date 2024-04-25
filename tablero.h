#pragma once
class Tablero
{
private:
	//guardian shift 8
	//capitan shift 4
	//exploradr shift 0

	// exp , cap , guard 
	int cantidades[3] = { 0,0,0 };

	int* tab[11];
	int* tab_back[11];
	bool casillas_bloqueadas[44];


	int tiene_capitan(int jugador_id, int columna, bool guardianes);
	int tiene_explorador(int jugador_id, int columna, bool guardianes);


public:
	int size[11] = { 3,5,7,9,11,13,11,9,7,5,3 };
	Tablero();
	~Tablero();
	int traducir_codigo(int a);
	int mover_ficha(int jugador_id, int columna, bool capitan);
	void eliminar_guardian(int jugador_id, int columna);
	bool validar_combinacion(int jugador_id, int columna, int columna2, bool capitan, bool capitan2);
	void imprimir_tablero();
	bool columna_bloqueada(int jugador_id, int columna);
	void forzar_cambio(int valor, int fila, int columna);
	int** retornar_tablero();
	int* cantidad_fichas(int jugador_id);

	void perder_turno(int jugador_id);
	void cerrar_turno(int jugador_id);

	void reload() {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < size[i]; j++) {
				tab_back[i][j] = tab[i][j];
			}
		}
	};
};

