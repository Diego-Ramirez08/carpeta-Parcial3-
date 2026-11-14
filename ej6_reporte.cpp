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

void ordenar(Alumno alumnos[], float promedio[], int cantidad)
{
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - 1 - i; j++)
        {
            if (promedio[j] < promedio[j + 1])
            {
                float temporalPromedio = promedio[j];
                promedio[j] = promedio[j + 1];
                promedio[j + 1] = temporalPromedio;

                Alumno temporalAlumno = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temporalAlumno;
            }
        }
    }
}

int main()
{
    Alumno alumnos[5];
    float promedio[5];

    ifstream archivo("Alumnos.txt");

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo original." << endl;
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

    ordenar(alumnos, promedio, 5);

    ofstream reporte("Reporte.txt");

    if (!reporte.is_open())
    {
        cout << "No se pudo crear el reporte." << endl;
        return 1;
    }

    reporte << fixed << setprecision(1);

    reporte << "REPORTE DE ALUMNOS ORDENADOS POR PROMEDIO\n\n";

    for (int i = 0; i < 5; i++)
    {
        reporte << "Nombre: " << alumnos[i].nombre << endl;
        reporte << "Matricula: " << alumnos[i].matricula << endl;

        for (int j = 0; j < 3; j++)
        {
            reporte << "Calificacion " << j + 1 << ": "
                    << alumnos[i].calificaciones[j] << endl;
        }

        reporte << "Promedio: " << promedio[i] << endl;
        reporte << "-----------------------------" << endl;
    }

    cout << "El reporte se genero correctamente." << endl;

    return 0;
}
