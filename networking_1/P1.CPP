/*
Practica 1 Sistema de Comunicacion de Datos

Autores:
-David Mesa Barragan
-Mario Corchero Jimenez

3� Ingenieria Informatica
*/

#include "STDIO.H"
#include "CONIO.H"
#include "interfaz.h"
#include "imodem.h"



void IntroducirParametros(TCom &Puerto,char nom_puerto[5], int &bps, int &bits, char paridad[9], int &parada)
{

	int op1, op2, op3, op4, op5;


	do
	{
		printf("Selecciona el puerto correspondiente\n");
		printf("1.- COM1\n");
		printf("2.- COM2\n");
		printf("3.- COM3\n");
		printf("4.- COM4\n");
		scanf("%d", & op1);

		switch(op1)
		{
		case 1:
			Puerto.AbrirPuerto(COM1); strcpy(nom_puerto, "COM1");
			break;
		case 2:
			Puerto.AbrirPuerto(COM2);strcpy(nom_puerto, "COM2");
			break;
		case 3:
			Puerto.AbrirPuerto(COM3);strcpy(nom_puerto, "COM3");
			break;
		case 4:
			Puerto.AbrirPuerto(COM4);strcpy(nom_puerto, "COM4");
			break;

		}
	}while(op1 <1 || op1 > 4);

	do
	{
		printf("Selecciona la velocidad en Bps\n");
		printf("1.- 2400\n");
		printf("2.- 4800\n");
		printf("3.- 9600\n");
		printf("4.- 19200\n");
		scanf("%d", & op2);

		switch(op2)
		{
		case 1:
			Puerto.EstablecerBPS(2400); bps = 2400;
			break;
		case 2:
			Puerto.EstablecerBPS(4800); bps = 4800;
			break;
		case 3:
			Puerto.EstablecerBPS(9600); bps = 9600;
			break;
		case 4:
			Puerto.EstablecerBPS(19200); bps = 19200;
			break;
		}
	}while(op2 <1 || op2 > 4);


	do
	{
		printf("Selecciona los bits de datos\n");
		printf("1.- 7\n");
		printf("2.- 8\n");
		scanf("%d", &op3);

		switch(op3)
		{
		case 1:
			Puerto.EstablecerBitsDatos(7); bits = 7;
			break;
		case 2:
			Puerto.EstablecerBitsDatos(8); bits  = 8;
			break;
		}
	}while(op3 <1 || op3 > 2);



	do
	{
		printf("Selecciona el tipo de paridad\n");
		printf("1.- Ninguno\n");
		printf("2.- Impar\n");
		printf("3.- Par\n");
		printf("4.- Marca\n");
		printf("5.- Espacio\n");
		scanf("%d", &op4);

		switch(op4)
		{
		case 1:
			Puerto.EstablecerParidad(NINGUNO); strcpy(paridad,"NINGUNO");
			break;
		case 2:
			Puerto.EstablecerParidad(IMPAR); strcpy(paridad,"IMPAR");
			break;
		case 3:
			Puerto.EstablecerParidad(PAR); strcpy(paridad,"PAR");
			break;
		case 4:
			Puerto.EstablecerParidad(MARCA); strcpy(paridad,"MARCA");
			break;
		case 5:
			Puerto.EstablecerParidad(ESPACIO);  strcpy(paridad,"ESPACIO");
			break;
		}
	}while(op2 <1 || op2 > 5);


	do
	{
		printf("Selecciona el bit de parada\n");
		printf("1.- 1\n");
		printf("2.- 2\n");
		scanf("%d", &op5);

		switch(op5)
		{
		case 1:
			Puerto.EstablecerBitsParada(1); parada = 1;
			break;
		case 2:
			Puerto.EstablecerBitsParada(2); parada = 2;
			break;
		}
	}while(op3 <1 || op3 > 2);
	Puerto.VaciarBuffers();
}

void ConectarPorCable(TCom &Puerto,char nom_puerto[5], int &bps, int &bits, char paridad[9], int &parada)
{

	int salir = 0;  //bandera de fin de bucle
	char car;
	char salida;  //variable para mostrar la informacion recibida

	int contador = 0;

	Interfaz::Iniciar();
	Interfaz myI;

	myI.PintarPuertos(nom_puerto,bps,bits,paridad,parada);



	//Puerto.AbrirPuerto(COM1,9600,8,NINGUNO,1);
	myI.MostrarEstados(Puerto);

	//Mandamos se�al para que se actualicen los puertos en el otro terminal
	Puerto<<127;


	while(!salir)
	{
		if(kbhit())
		{
			car = getch();
			myI.Enviar(Puerto,salir,car, contador);
		}
		//Vemos si hay caracteres para leer
		if(Puerto.OcupacionBufferEntrada() !=0)
		{
			Puerto>>salida;
			if(salida == 127) myI.MostrarEstados(Puerto);
			else if(salida == 126) myI.RecibirFichero(Puerto,salir, contador);
			else myI.Recepcion(salida);
		}
	}
	myI.Informacion("Fin del programa");
}

void ConectarPorModem(TCom &Puerto,char nom_puerto[5], int &bps, int &bits, char paridad[9], int &parada)
{
	int salir = 0;
	char car;
	IModem::Iniciar();
	IModem myI(&Puerto);

	myI.PintarPuertos(nom_puerto,bps,bits,paridad,parada);

	while(!salir)
	{
		if(kbhit())
		{
			car = getch();
			myI.Procesar(car, salir);
		}
		myI.Recibir();

	}


}

void main ()
{
	TCom Puerto;


	int bps, bits, parada;
	char nom_puerto[5], paridad[9];
	IntroducirParametros(Puerto,nom_puerto,bps,bits,paridad,parada);


	if(strcmp("COM1",nom_puerto) == 0)
		ConectarPorCable(Puerto,nom_puerto,bps,bits,paridad,parada);
	else if(strcmp("COM4",nom_puerto) == 0)
		ConectarPorModem(Puerto,nom_puerto,bps,bits,paridad,parada);
	else printf("Error, puerto incorrecto \n");



	Puerto.CerrarPuerto();
	getch();
}