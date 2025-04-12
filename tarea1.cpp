#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void main()
{
	int opc, N, N2, a, dif, dado1, dado2, sumd;
	float Lineas, Suma;
 	system("clear");
cout << "1. Calcular el numero de lineas telefonicas para N suscriptores con la formula        Lineas=(n(n-1)/2)"<<endl;
	cout << "2. Calcula la suma de un rango de numeros con la formula 
Suma=(n/2)(2a +(n-1)d)" << endl;
	cout << "3. Simula el lanzamiento de un par de dados y suma sus resultados" << endl;
	cout << "4. Salir del Menu" << endl;
	cout << "ingrese la opcion deseada" << endl;
	cin >> opc;
	switch (opc)
	{
	case 1:{
			   cout << "ingrese el numero de suscriptores"<<endl;
			   cin >> N;
			   Lineas = ((N*(N - 1)) / 2);
			   cout << "el numero de lineas es: "<< Lineas << endl;
	} break;
	case 2:{
			   cout << "Ingrese el numero de terminos a sumar:" << endl;
			   cin >> N2;
			   cout << "ingrese el primer numero" << endl;
			   cin >> a;
			   cout << "ingrese la diferencia entre cada numero: " << endl;
			   cin >> dif;
			   Suma = (N2 / 2)*((2 * a) + (N2 - 1)*dif);
			   cout << "la suma del rango es: " << Suma << endl;
	} break;
	case 3:{
			   dado1 = rand() % 7;
			   cout << "el valor del dado 1 es igual a: " << dado1 << endl;
			   dado2 = rand() % 7;
			   cout << "el valor del dado 2 es igual a: " << dado2 << endl;
			   sumd = dado1 + dado2;
			   cout << "la suma de los dados es: " << sumd << endl;
	} break;
	case 4: { system("exit"); }
	default: break;
	}
	system("pause"); }
