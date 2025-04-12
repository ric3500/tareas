#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void p_igss();
int main()
{
	system("cls");
	p_igss();
	system("pause");
	return 0;
}
void p_igss()
{
	float sueldo_liquido, igss, total;
	cout << "ingrese el sueldo liquido del empleado: " << endl;
	cin >> sueldo_liquido;
	igss = (sueldo_liquido*4.83) / 100;
	total = sueldo_liquido - igss;
	cout << "El descuento del IGSS es de: "<< igss << endl; 
	cout << "El sueldo a recibir es de: "<< total << endl;
}
