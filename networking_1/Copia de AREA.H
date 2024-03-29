
#ifndef AREA_H
#define AREA_H

#include <stdio.h>
#include <graphics.h>
#include <conio.h>

struct Posicion{
	int x;
	int y;
};


class Area{
public:
	Area(Posicion inicio, int largo, int alto, char titulo[] );
	Area(int iniciox, int inicioy, int largo, int alto,char titulo[]);


	void EscribirMensaje(char mensaje[]);
	void EscribirChar(char caracter);


protected:
	Posicion actual;  //Posicion actual en la que escribir.
	Posicion inicio;  //Posicion inicial del area.
	int largo; //Largo del area sin  bordes.
	int alto; //Alto del area sin incluir bordes.
	void PintarArea(); //Funcion para pintar el "entorno" del area.
	virtual	void SaltoDeLinea();
};




#endif //de AREA_h