#include "Matriz.h"

Matriz::Matriz (){
	tablero = new char*[11];
	for (int i = 0; i < 12; ++i)
	{
		tablero[i] = new char[11];
	}

	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			tablero[i][j] = ' ';
		}
	}
	tablero[0][0]='#';
	tablero[10][10]='#';
	tablero[10][0]='+';
	tablero[0][10]='+';
}

void Matriz::imprimir(){
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			cout<<"[ "<<tablero[i][j]<<" ] ";
		}
		cout<<endl;
	}
}

bool Matriz::VerificarGane(){
	int contSharp=0, contMas=0, contVacio=0;

	//Verificar si hay casillas vacias y contar Fichas de cada jugador
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if(this->tablero[i][j]==' '){
				contVacio++;
			}else{
				if(this->tablero[i][j]=='#'){
					contSharp++;
				}
				if(this->tablero[i][j]=='+'){
					contMas++;
				}
			}
		}
	}
	if (contVacio==0)
	{
		if(contSharp==0 && contMas!=0){
			cout<<"Ganaron los positivos"<<endl;
			return true;
			borrarTablero();
		}
		if(contSharp!=0 && contMas==0){
			cout<<"Ganaron los hashtags"<<endl;
			return true;
			borrarTablero();
		}
		if(contMas==contSharp){
			cout<<"Quedaron empatados"<<endl;
			return true;
			borrarTablero();
		}
	}
	return false;
}


bool Matriz::Mover(int X, int Y, int xOriginal, int yOriginal, char Player){

	if(X<0 || Y<0 || X>11 || Y>11){
		cout<<"El valor esta out of bound"<<endl;
		return false;
	}else if(X>(xOriginal+2) || Y>(yOriginal+2)){
		cout<<"No se puede mover mas de dos espacios"<<endl;
		return false;
	}else if(tablero[Y][X]!=' '){
		cout<<"La casilla esta ocupada"<<endl;
		return false;
	}else if(tablero[yOriginal][xOriginal]!=Player){
		cout<<"La Ficha no es la del Jugador activo"<<endl;
		return false;
	}else{
		tablero[Y][X] = Player;
		//tablero[yOriginal][xOriginal]= ' ';
		if(Player=='#'){
			if((Y+1 < 11) || (Y-1 < 0) || (X+1 < 11) || (X-1 < 0)){
				if (tablero[Y+1][X]=='+' && (Y+1 < 11))
				{
					tablero[Y+1][X]='#';
				}
				//Diagonales CAMBIO
				if((Y!=0) && tablero[Y-1][X-1]=='+' && (X-1 > 0)){
					tablero[Y-1][X-1] = '#';
				}
				if(tablero[Y+1][X+1]=='+' && (X+1 < 10 && Y+1 < 11)){
					tablero[Y+1][X+1] = '#';
				}
				if((Y!=0) && tablero[Y-1][X+1]=='+' && (X+1 > 11)){
					tablero[Y-1][X+1] = '#';
				}
				if((Y+1<11) && tablero[Y+1][X-1]=='+' && (X-1 > 0)){
					tablero[Y+1][X-1] = '#';
				}
				// DIAGONALES CAMBIO END
				if(Y!=0){
					if (tablero[Y-1][X]=='+' && (Y-1 < 0))
					{
						tablero[Y-1][X]='#';
					}
				}
				if (tablero[Y][X+1]=='+' && (X+1 < 11))
				{
					tablero[Y][X+1]='#';
				}
				if (tablero[Y][X-1]=='+' && (X-1 > 0))
				{
					tablero[Y][X-1]='#';
				}
				return true;
			}else{
				return false;
			}
		}
		if(Player=='+'){
			if((Y+1 < 11) || (Y-1 < 0) || (X+1 < 11) || (X-1 < 0)){
				if (tablero[Y+1][X]=='#' && (Y+1 < 11))
				{
					tablero[Y+1][X]='+';
				}
				//Diagonales CAMBIO
				if((Y!=0) && tablero[Y-1][X-1]=='#' && (X-1 > 0)){
					tablero[Y-1][X-1] = '+';
				}
				if(tablero[Y+1][X+1]=='#' && (X+1 < 10 && Y+1 < 11)){
					tablero[Y+1][X+1] = '+';
				}
				if((Y!=0) && tablero[Y-1][X+1]=='#' && (X+1 > 11)){
					tablero[Y-1][X+1] = '+';
				}
				if((Y+1<11) && tablero[Y+1][X-1]=='#' && (X-1 > 0)){
					tablero[Y+1][X-1] = '+';
				}
				// DIAGONALES CAMBIO END
				if(Y!=0){
					if (tablero[Y-1][X]=='#' && (Y-1 < 0))
					{
						tablero[Y-1][X]='+';
					}
				}
				if (tablero[Y][X+1]=='#' && (X+1 < 11))
				{
					tablero[Y][X+1]='+';
				}
				if (tablero[Y][X-1]=='#' && (X-1 < 0))
				{
					tablero[Y][X-1]='+';
				}
				return true;
			}else{
				return false;
			}
		}
	}
}

Matriz::~Matriz(){
	for (int i = 0; i < 11; ++i)
	{
		delete[] tablero[i];
		tablero[i] = NULL;
	}
	delete[] tablero;
	tablero = NULL;
}