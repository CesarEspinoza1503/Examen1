#include <iostream>
#include "Matriz.h"


int main(int argc, char const *argv[])
{
	char Ficha;
	bool Gane = false;
	bool moveOn;
	int xFicha, yFicha, xMovimiento, yMovimiento;
	bool turnPlayer = true;
	int SalirPrograma = 1;
	Matriz* tablero = new Matriz();

	do
	{
		cout<<"			Examen 1 Laboratorio"<<endl<<"Pseudo Ataxx"<<endl;
		cout<<"1)Empezar un Juego"<<endl<<"2)Salir"<<endl;
		cin>>SalirPrograma;
		if (SalirPrograma==1)
		{
			tablero->imprimir();
			do
			{

				while(turnPlayer==true){
					Ficha = '+';
					cout<<"Ingrese coordenada de la Ficha a mover ("<<Ficha<<") "<<endl<<"X: ";
					cin>>xFicha;
					cout<<"Y: ";
					cin>>yFicha;
					cout<<"Mover hacia :"<<endl<<"X: ";
					cin>>xMovimiento;
					cout<<"Y: ";
					cin>>yMovimiento;
					moveOn = tablero->Mover(xMovimiento,yMovimiento,xFicha,yFicha, Ficha);
					tablero->imprimir();
					if(moveOn==true){
						turnPlayer=false;
					}
				}
				while(turnPlayer==false){
					Ficha = '#';
					cout<<"Ingrese coordenada de la Ficha a mover ("<<Ficha<<") "<<endl<<"X: ";
					cin>>xFicha;
					cout<<"Y: ";
					cin>>yFicha;
					cout<<"Mover hacia :"<<endl<<"X: ";
					cin>>xMovimiento;
					cout<<"Y: ";
					cin>>yMovimiento;
					tablero->Mover(xMovimiento,yMovimiento,xFicha,yFicha, Ficha);
					tablero->imprimir();
					if(moveOn==true){
						turnPlayer=true;
					}
					
				}
			} while (Gane==false);
		}
	} while (SalirPrograma!=2);
	

	return 0;
}