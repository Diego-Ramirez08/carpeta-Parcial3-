#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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

    ifstream archivo("Alumnos.txt");

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        string dato;

        getline(archivo, alumnos[i].nombre, '|');
        getline(archivo, alumnos[i].matricula, '|');

        for (int j = 0; j < 3; j++)
        {
            getline(archivo, dato, '|');
            alumnos[i].calificaciones[j] = stof(dato);
        }

        getline(archivo, dato);
        promedio[i] = stof(dato);
    }

    cout << fixed << setprecision(1);

    cout << "\n--- ALUMNOS REGISTRADOS ---\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "\nNombre: " << alumnos[i].nombre << endl;
        cout << "Matricula: " << alumnos[i].matricula << endl;

        for (int j = 0; j < 3; j++)
        {
            cout << "Calificacion " << j + 1 << ": "
                << alumnos[i].calificaciones[j] << endl;
        }

        cout << "Promedio: " << promedio[i] << endl;
    }

    return 0;
}