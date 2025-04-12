#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <time.h>

// Estructura del registro de los empleados
struct empleado
{
char cod[6], puesto[30], nombres[75], apellidos[75];
int edad;
float sueldo;
};

// Declaracion de las funciones
int menu();
void regempleados();
void mostrareg();
void busdatos();
void lista();
bool encontrado = false;
bool repetido = false;

int main()
{
   clrscr();
   menu();
   getch();
   return 0;
}

// funcion del menu
int menu()
{
  int opc;
  do {
   clrscr();
   cout << "\t\t MENU" << endl;
   cout << "######################################\n";
   cout << "1. Ingresar registro de empleado. " <<endl;
   cout << "2. Mostrar los registros de empleado. " << endl;
   cout << "3. Buscar un registro de empleado. " << endl;
   cout << "4. Modificar registro de empleado. " << endl;
   cout << "5. Eliminar un registro de empleado. " << endl;
   cout << "6. Generar reporte. " << endl;
   cout << "7. Salir." << endl;
   cout << "###################################### \n";
   cout << "Eliga una opcion: ";
   cin >> opc;
   switch(opc)
   {
    case 1:   //Opcion de guardar registros en archivo
    {
    regempleados();
    }break;
    case 2:   //Opcion de mostrar registros de empleados
    {
        mostrareg();
    }break;
    case 3: //funcion para buscar registro de empleado por codigo
    {
     busdatos(); 
    }break;
    case 4: 
    {
     //funcion para modificar un registro de empleado
    }break;
    case 5:  
    {
        //funcion para eliminar un registro  
    }break;
    case 6:      
    {
       //funcion para crear un registro
    }break;
    case 7:   //Opcion Salir
    { exit(1);  }break;
   }
}while(opc !=7);
}

//funcion para guardar registros de empleados
void regempleados()
{
   ofstream guardar;
   ifstream consulta;
   repetido = false;
   guardar.open("registro.dat", ios::out | ios::app |ios::binary);
   consulta.open("registro.dat", ios::in |ios::binary);
   empleado emp;
   int tam = sizeof(empleado);
   char ccod[6];
   char resp;
   clrscr();
   cout << "\t .: Ingresando registros del empleado :. \n";
   cout << "ingrese el codigo del empleado. ";
   cin >> ccod;
   consulta.read((char *)&emp.cod, tam);
   while (!consulta.eof())
   {
    if(strstr(ccod, emp.cod)!=NULL)
    {
   cout << "El codigo ya existe"<< endl;
   repetido = true;
   break;
    }
      consulta.read((char *)&emp.cod, tam);
    }
   if (repetido ==false)
{
strcpy(emp.cod, ccod);
cout << "ingrese el nombre del empleado.\n";
gets(emp.nombres);
cout << "ingrese el apellido del empleado.\n";
gets(emp.apellidos);
cout << "ingrese la edad del empleado en numeros.\n";
cin >> emp.edad;
cout << "ingrese el puesto: ";
gets(emp.puesto);
cout << "ingrese el sueldo del empleado. ";
cin >> emp.sueldo;
//ingresar los datos en el archivo
guardar.write((char *)&emp, tam);
}
   guardar.close();
   consulta.close();
   cout << "Desea agregar otro registro s/n: ";
   cin >> resp;
   if (resp=='s')
   {  regempleados();  }
   else
   {menu();}
}

   //Funcion para mostrar los registros de empleado
void mostrareg()
{
      clrscr();
      ifstream leer;
      empleado registro;
      int tam = sizeof(empleado);
      leer.open("registro.dat", ios::binary);
      //comprueba si el archivo existe si no existe no hay registros
      if (leer.fail())
      {
      cout << ".: No existen registros:. ";
      getch();
      menu();
      }
      cout << " \t\t.: Mostrando todos los registros :.\n" << endl;
      //aqui se lee el archivo para usarse en el ciclo
      leer.read((char *)&registro, tam);
      while(!leer.eof())
      {
      cout << "######################################" << endl;
      cout << "Codigo: " << registro.cod << endl;
      cout << "Nombre: " << registro.nombres << endl;
      cout << "Apellidos: " << registro.apellidos << endl;
      cout << "Edad " << registro.edad << endl;
      cout << "Puesto " << registro.puesto << endl;
      cout << "Sueldo " << registro.sueldo << endl;
      leer.read((char *)&registro, tam);
      }
      leer.close();
      cout << "\nPresione una tecla para continuar...";
      getch();
      menu();
   }

//funcion para buscar registros
void busdatos()
{
clrscr();
char ccod[6];
char resp;
empleado registro;
encontrado = false;
int tam = sizeof(empleado);
ifstream leer;
leer.open("registro.dat", ios::binary);
if (leer.fail())
      {
      cout << ".: No existen registros:. ";
      getch();
      menu();
      }
cout << "\t\t\t.:Busqueda de un Registro :.\n" << endl;
leer.read((char *)&registro.cod, tam);
cout << "Ingrese el codigo del registro: ";
cin >> ccod;

cout << "\n";
while(!leer.eof())
{
if(strstr (ccod, registro.cod)!=NULL)
{
      cout << "######################################" << endl;
      cout << "Nombre: " << registro.nombres << endl;
      cout << "Apellidos: " << registro.apellidos << endl;
      cout << "Edad " << registro.edad << endl;
      cout << "Puesto " << registro.puesto << endl;
      cout << "Sueldo " << registro.sueldo << endl;
      cout << "#####################################" << endl;
      encontrado = true;
 }
      leer.read((char *)&registro, tam);
  }
if(encontrado == false){
cout << "\n\n\t\t .: El registro no existe :.\n\n" << endl;
}
leer.close();
cout <<"\nDesea buscar otro registro (s/n): ";
cin >> resp;
if (resp == 's')
{ busdatos(); }
else 
{menu(); }
}
