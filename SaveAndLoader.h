#pragma once
#include "tablero.h"
#include <vector>
#include <iostream>
#include <fstream>



class SaveAndLoader
{
public:
	void save(std::string filename, int turno, Tablero* tablero, std::vector<std::string> nombres);
	void load(std::string filename, int* turno, Tablero* tablero, std::vector<std::string>* nombres);


	void save_board(Tablero* tablero, std::ofstream& filename);
	void load_board(Tablero* tablero, std::ifstream& infile);

	void save_names(std::vector<std::string> nombres, std::ofstream& filename);
	void load_names(std::vector<std::string>* nombres, std::ifstream& infile);

	void save_turno(int turno, std::ofstream& filename);
	int load_turno(std::ifstream& infile);

};

