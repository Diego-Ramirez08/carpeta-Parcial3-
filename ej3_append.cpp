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
    Alumno nuevo;
    float suma = 0;
    float promedio;

    cout << "Nombre del nuevo alumno: ";
    getline(cin, nuevo.nombre);

    cout << "Matricula: ";
    getline(cin, nuevo.matricula);

    for (int i = 0; i < 3; i++)
    {
        cout << "Calificacion " << i + 1 << ": ";
        cin >> nuevo.calificaciones[i];

        suma += nuevo.calificaciones[i];
    }

    promedio = suma / 3;

    ofstream archivo("Alumnos.txt", ios::app);

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    archivo << fixed << setprecision(1);

    archivo << nuevo.nombre << "|"
            << nuevo.matricula << "|";

    for (int i = 0; i < 3; i++)
    {
        archivo << nuevo.calificaciones[i] << "|";
    }

    archivo << promedio << endl;

    cout << "\nEl nuevo alumno se agrego correctamente." << endl;

    return 0;
}
