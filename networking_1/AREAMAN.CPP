
#include "areaman.h"


AreaMan::AreaMan(Posicion inicio, int largo, int alto, char titulo[]):
Area(inicio.x,inicio.y,largo, alto,titulo)
{
}

AreaMan::AreaMan(int iniciox, int inicioy, int largo, int alto, char titulo[]):
Area(iniciox, inicioy, largo, alto, titulo)
{
}

void AreaMan::SaltoDeLinea(){
	actual.y+=10;
	actual.x = inicio.x+2;
	if((actual.y-inicio.y) >alto){
		actual.y = inicio.y+2+10;
		getch();//esperamos que pulse una tecla para borrar
		bar(actual.x,actual.y,inicio.x+largo-2,actual.y+alto-12);
	}
}