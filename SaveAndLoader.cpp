#include "SaveAndLoader.h"
#include <string>
#include <chrono>

int get_timps() {
	auto now = std::chrono::system_clock::now();
	auto epoch = now.time_since_epoch();
	auto seconds = std::chrono::duration_cast<std::chrono::seconds>(epoch);

	return seconds.count();
}

void SaveAndLoader::save(std::string filename, int turno, Tablero* tablero, std::vector<std::string> nombres)
{
	std::ofstream outfile(filename, std::ios::out | std::ios::binary);

	save_board(tablero, outfile);
	save_names(nombres, outfile);
	save_turno(turno, outfile);

	outfile.close();
}

void SaveAndLoader::load(std::string filename, int* turno, Tablero* tablero, std::vector<std::string>* nombres)
{
	std::ifstream infile(filename, std::ios::in | std::ios::binary);
	load_board(tablero, infile);
	load_names(nombres, infile);
	turno[0] = load_turno(infile);
	infile.close();
}

void SaveAndLoader::save_board(Tablero* tablero, std::ofstream& outfile)
{


	int** tab = tablero->retornar_tablero();
	for (int i = 0; i < 11; ++i) {
		for (int j = 0; j < tablero->size[i]; ++j) {
			outfile.write(reinterpret_cast<const char*>(&tab[i][j]), sizeof(int));
		}
	}


}

void SaveAndLoader::load_board(Tablero* tablero, std::ifstream& infile)
{
	
	int** tab = tablero->retornar_tablero();
	for (int i = 0; i < 11; ++i) {
		for (int j = 0; j < tablero->size[i]; ++j) {
			infile.read(reinterpret_cast<char*>(&tab[i][j]), sizeof(int));
		}
	}

}

void SaveAndLoader::save_names(std::vector<std::string> nombres, std::ofstream& outfile)
{

	int cantidadNombres = nombres.size();
	outfile.write(reinterpret_cast<const char*>(&cantidadNombres), sizeof(int));

	for (const std::string& nombre : nombres) {

		int longitudNombre = nombre.size();
		outfile.write(reinterpret_cast<const char*>(&longitudNombre), sizeof(int));


		outfile.write(nombre.c_str(), longitudNombre);
	}




}

void SaveAndLoader::load_names(std::vector<std::string>* nombres, std::ifstream& infile)
{

	int cantidadNombres;
	infile.read(reinterpret_cast<char*>(&cantidadNombres), sizeof(int));

	for (int i = 0; i < cantidadNombres; ++i) {


		int longitudNombre;
		infile.read(reinterpret_cast<char*>(&longitudNombre), sizeof(int));
		char* buffer = new char[longitudNombre + 1];
		infile.read(buffer, longitudNombre);
		buffer[longitudNombre] = '\0';

		std::string nombre(buffer);
		nombres->push_back(nombre);

		delete[] buffer;
	}
}

void SaveAndLoader::save_turno(int turno, std::ofstream& outfile)
{
	outfile.write(reinterpret_cast<const char*>(&turno), sizeof(int));
}

int SaveAndLoader::load_turno(std::ifstream& infile)
{

	int turno;
	infile.read(reinterpret_cast<char*>(&turno), sizeof(int));

	return turno;
}


