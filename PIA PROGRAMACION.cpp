#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>
#include <vector>

using namespace std;


void Alta();
void listas();
void archivos();
void eliminar();
void modificar();

int alta, * cant, * precio, * subtotal, * iva, * total;
string* nombre, * horario, * nombreT, * desc;
int main()
{
	int opc;
	cout << "1.-Alta" << endl << "2.- mostrar" << endl << "3.- limpiar pantalla" << endl << "4.-Modificar" << endl << "5.-Eliminar" << endl << "6.-Salir" << endl;
	cin >> opc;

	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;

	case 2:
		listas();
		return main();
		break;

	case 3:
		system("cls"); 
		return main();
		break;

	case 4:
		modificar();
		return main();
		break;

	case 5:
		eliminar();
		return main();
		break;

	case 6:
		archivos();
		break;
	}
}

void Alta()
{
	cout << "Digite el num de registros que desea dar de alta" << endl;
	cin >> alta;
	cin.ignore();
	nombre = new string[alta];
	horario = new string[alta];
	nombreT = new string[alta];
	desc = new string[alta];
	cant = new int[alta];
	precio = new int[alta];
	total = new int[alta];

	for (int i = 0; i < alta; i++)
	{

		cout << "Ingrese nombre" << endl;
		getline(cin, nombre[i]);
		cout << "Ingrese horario" << endl;
		getline(cin, horario[i]);
		cout << "Ingrese nombre tratamiento" << endl;
		getline(cin, nombreT[i]);
		cout << "Ingrese descripcion" << endl;
		getline(cin, desc[i]);
		cout << "ingrese cantidad tratamiento";
		cin >> cant[i];
		cin.ignore();
		cout << "ingrese precio unitario";
		cin >> precio[i];
		total[i] = cant[i] * precio[i];
		cin.ignore();
	}
}

void mostrar()
{
	for (int i = 0; i < alta; i++)
	{
		cout << " registro" << i + 1 << endl;
		cout << nombre[i] << endl;
		cout << horario[i] << endl;
		cout << nombreT[i] << endl;
		cout << desc[i] << endl;
		cout << total[i] << endl;
	}
}

void archivos()
{
	ofstream archivo; 
	string nombrearchivo;
	int txt = 0;
	string texto2, texto;

	nombrearchivo = "citas.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	archivo << "Nombre del paciente:" << "\t";
	archivo << "Horario:" << "\t";
	archivo << "nombre tratamiento" << "\t";
	archivo << "descripcion" << "\t";
	archivo << "total:" << "\n";

	for (int i = 0; i < alta; i++)
	{
		texto = nombre[i];
		archivo << texto << "\t" << "\t";
		texto2 = horario[i];
		archivo << texto2 << "\t" << "\t";
		texto = nombreT[i];
		archivo << texto << "\t " << "\t";
		texto = desc[i];
		archivo << txt << "\t " << "\t";
		texto = total[i];
	}


	archivo.close();
}

void eliminar()
{
	int j;
	cout << "ingrese el  registro a eliminar";
	cin >> j;
	j = j - 1;
	nombre = new string[alta];

	for (int i = j; i == j; i++)
	{

		nombre[i] = ' ';
		horario[i] = ' ';
		nombreT[i] = ' ';
		desc[i] = ' ';
		total[i] = 0;
	}
}

void modificar()
{
	int j, opcion;
	cout << "ingrese el numero registro a modificar";
	cin >> j;
	j = j - 1; 
	cout << "ingrese que desea modificar 1.-nombre,2.-horario, 3.- nombre tratamiento 4.- descripcion 5.-cantidad tratamientos 6.-precio unitario" << endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese nombre" << endl;
			getline(cin, nombre[i]);
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese horario" << endl;
			getline(cin, horario[i]);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese nombre tratamiento" << endl;
			getline(cin, nombreT[i]);
		}
		break;

	case 4:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese descripcion tratamiento" << endl;
			getline(cin, desc[i]);
		}
		break;
	case 5:
		for (int i = j; i == j; i++)
		{
			cout << "ingrese cantidad tratamiento";
			cin >> cant[i];
			cin.ignore();
			total[i] = cant[i] * precio[i];
		}
		break;
	case 6:
		for (int i = j; i == j; i++)
		{
			cout << "ingrese precio unitario tratamiento";
			cin >> precio[i];
			cin.ignore();
			total[i] = cant[i] * precio[i];
		}
		break;
	}
}
