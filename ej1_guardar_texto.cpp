#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Alumno
{
    string nombre;
    string matricula;
    float calificaciones[3];
};

int main()
{
    Alumno alumnos[5];
    float promedio[5];

    for (int i = 0; i < 5; i++)
    {
        float suma = 0;

        cout << "\nNombre del alumno " << i + 1 << ": ";
        getline(cin, alumnos[i].nombre);

        cout << "Matricula: ";
        getline(cin, alumnos[i].matricula);

        for (int j = 0; j < 3; j++)
        {
            cout << "Calificacion " << j + 1 << ": ";
            cin >> alumnos[i].calificaciones[j];

            suma += alumnos[i].calificaciones[j];
        }

        promedio[i] = suma / 3;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ofstream archivo("Alumnos.txt");

    if (!archivo.is_open())
    {
        cout << "No se pudo crear el archivo." << endl;
        return 1;
    }

    archivo << fixed << setprecision(1);

    for (int i = 0; i < 5; i++)
    {
        archivo << alumnos[i].nombre << "|"
                << alumnos[i].matricula << "|";

        for (int j = 0; j < 3; j++)
        {
            archivo << alumnos[i].calificaciones[j] << "|";
        }

        archivo << promedio[i] << endl;
    }

    cout << "\nLos alumnos se guardaron correctamente." << endl;

    return 0;
}