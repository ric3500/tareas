#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
float f_vol_esfera();
void main()
{
system("cls");
float result;
result = f_vol_esfera();
cout << "El volumen de la esfera es: " << result << endl;
system("pause");
}

float f_vol_esfera()
{
const float pi = 3.141592;
float rad, vol;
cout << "ingrese el Radio de la esfera" << endl;
cin >> rad;
vol = (pow(rad,3)*(1.3333*pi)); 
return vol;
}
