#include <iostream>

#include <stdlib.h>

#include <string.h>

#include <string>

#include <fstream>

using namespace std;
void registro();
void modificar();
void borrar();
void mostrar();
void guardar();
struct citas
{
	string NameP, hCita, NameT, DesT;
	float PrUT, CanT, total;
};
int op, rep, decision, i, j = 1, op2, elim;
citas datos[99];
ofstream archivo;
string nombrearchivo;
int main() {

	

	cout << "SELECCIONE UNA OPCION\n\t 1. hacer una de citas 2. modificar citas 3. eliminar cita 4. ver citas vigentes 5. limpiar pantalla 6. salir \n";
	cin >> op;
	cin.ignore();
	switch (op)
	{

	case 1://solicita los datos para poder agendar la cita
		registro();
		return main();
		break;
	case 2:
		modificar();
		return main();
		break;
	case 3:
		borrar();
		return main();
		break;
	case 4://muestra las citas registradas en el case 1
		mostrar();
		return main();
		break;
	case 5:
		system("cls");
		return main();
		break;
	case 6:
		guardar();
		exit(0);
	default:
		cout << "no ingreso una opcion valida\n";
		break;
	}

	cout << "vuelva pronto";
	return 0;
}
void registro()
{
	for (i = 0; i < j; i++)
	{
		if ((datos[i].NameP).empty())
		{


			cout << i + 1 << ".-ingrese el nombre del paciente: ";
			getline(cin, (datos[i].NameP));
			cout << "\ningrese hora del tratamiento(formato 24 hrs): ";
			getline(cin, (datos[i].hCita));
			cout << "\ningrese el nombre del tratamiento: ";
			getline(cin, (datos[i].NameT));
			cout << "\ningrese la descripcion del tratamiento:";
			getline(cin, (datos[i].DesT));
			cout << "\ningrese el precio unitario del tratamiento: ";
			cin >> (datos[i].PrUT);
			cin.ignore();
			cout << "\ningrese cuantos tratamientos seran: ";
			cin >> (datos[i].CanT);
			cin.ignore();
			cout << "desea ingresar otra cita? 1.-si 2.- no\n";
			cin >> rep;
			cin.ignore();

			if (rep == 1)
			{
				j = j + 1;

			}

		}
	}
}
void modificar()
{
	cout << "que cita quiere modificar?\n";
	cin >> j;
	j = j - 1;
	cin.ignore();
	if ((datos[j].NameP).empty())
	{
		cout << "no existe una cita con ese ID\n";
	}
	else
	{


		cout << "que apartado es el que se va modificar\n 1.-nombre del paciente\n2.-la hora del tratamiento\n3.- el nombre del tratamiento\n4.- la descripcion del tratamiento\n5.- el precio del tratamiento\n6.-la cantidad de tratamientos\n7.-todo\n";
		cin >> op2;
		cin.ignore();
		switch (op2)
		{
		case 1:
			for (i = j; i <= j; i++)
			{
				cout << "ingrese el nombre del paciente: ";
				getline(cin, (datos[i].NameP));
			}
			break;
		case 2:
			for (i = j; i <= j; i++)
			{
				cout << "ingrese el horario de la cita: ";
				getline(cin, (datos[i].hCita));
			}
			break;
		case 3:
			for (i = j; i <= j; i++)
			{
				cout << "ingrese el nombre del tratamiento: ";
				getline(cin, (datos[i].NameT));
			}
			break;
		case 4:
			for (i = j; i <= j; i++)
			{
				cout << "ingrese la descripcion del tratamiento: ";
				getline(cin, (datos[i].DesT));
			}
			break;
		case 5:
			for (i = j; i <= j; i++)
			{
				cout << "ingrese el precio del tratamiento: ";
				cin >> (datos[i].PrUT);
				cin.ignore();
			}
			break;
		case 6:
			for (i = j; i <= j; i++)
			{
				cout << "ingrese la cantidad de tratamientos: ";
				cin >> (datos[i].CanT);
				cin.ignore();
			}
			break;
		case 7:
			for (i = j; i <= j; i++)
			{
				cout << "ingrese el nombre del paciente: ";
				getline(cin, (datos[i].NameP));
				cout << "\ningrese el horario de la cita: ";
				getline(cin, (datos[i].hCita));
				cout << "\ningrese el nombre del tratamiento: ";
				getline(cin, (datos[i].NameT));
				cout << "\ningrese la descripcion del tratamiento: ";
				getline(cin, (datos[i].DesT));
				cout << "\ningrese el precio del tratamiento: ";
				cin >> (datos[i].PrUT);
				cin.ignore();
				cout << "\ningrese la cantidad de tratamientos: ";
				cin >> (datos[i].CanT);
				cin.ignore();
			}
			break;
		}
	}
}
void borrar()
{
	cout << "ingrese el numero de cita que desea eliminar\n";
	cin >> elim;
	elim = elim - 1;
	(datos[elim].NameP) = (datos[elim].NameP).empty();
	(datos[elim].hCita) = (datos[elim].hCita).empty();
	(datos[elim].NameT) = (datos[elim].NameT).empty();
	(datos[elim].DesT) = (datos[elim].DesT).empty();
	(datos[elim].PrUT) = 0;
}
void mostrar()
{

	j = 1;
	if ((datos[0].NameP).empty())
	{
		cout << "no hay citas vigentes\n";
	}
	else
	{

		cout << "citas vigentes:\n";
		for (i = 0; i < j; i++)
		{
			if (!(datos[i].NameP).empty())
			{
				datos[i].total = datos[i].PrUT * datos[i].CanT;
				cout << endl << i + 1 << ".- nombre: " << datos[i].NameP << endl << "hora de la cita: " << datos[i].hCita << endl << "Tratamiento: " << datos[i].NameT << endl << "Descripcion del tratamiento: " << datos[i].DesT << endl << "Total: " << datos[i].total << endl;
				j = j + 1;
			}

		}
	}
}
void guardar()
{

	archivo.open("citas.txt", ios::out);

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR";
		exit(1);
	}

	j = 1;
	for (i = 0; i < j; i++)
	{
		if (!(datos[i].NameP).empty())
		{
			archivo << i + 1 << ".- nombre: " << datos[i].NameP << endl;
			archivo << "hora de la cita: " << datos[i].hCita << endl;
			archivo << "Tratamiento: " << datos[i].NameT << endl;
			archivo << "Descripcion del tratamiento: " << datos[i].DesT << endl;
			archivo << "Total: " << datos[i].total << endl;
			j = j + 1;
		}
	}
	archivo.close();
}