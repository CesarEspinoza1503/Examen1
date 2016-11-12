#ifndef MATRIZ_H
#define MATRIZ_H

#include <string>
#include <iostream>

using namespace std;

class Matriz
{
public:
	char** tablero;
	Matriz();
	void crearTablero();
	void imprimir();
	bool VerificarGane();
	bool Mover(int, int, int, int, char);
	void Clonar();
	void borrarTablero();
	~Matriz();
	
};


#endif