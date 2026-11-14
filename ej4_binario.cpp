#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

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
        cout << "No se pudo abrir el archivo de texto." << endl;
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

    ofstream binario("Alumnos.bin", ios::binary);

    if (!binario.is_open())
    {
        cout << "No se pudo crear el archivo binario." << endl;
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        size_t longitud = alumnos[i].nombre.size();

        binario.write(reinterpret_cast<char*>(&longitud), sizeof(longitud));
        binario.write(alumnos[i].nombre.data(), longitud);

        longitud = alumnos[i].matricula.size();

        binario.write(reinterpret_cast<char*>(&longitud), sizeof(longitud));
        binario.write(alumnos[i].matricula.data(), longitud);

        binario.write(
            reinterpret_cast<char*>(alumnos[i].calificaciones),
            sizeof(alumnos[i].calificaciones)
        );

        binario.write(reinterpret_cast<char*>(&promedio[i]), sizeof(float));
    }

    binario.close();

    cout << "Archivo binario generado correctamente." << endl;

    cout << "\nTamano del archivo de texto: "
        << filesystem::file_size("Alumnos.txt")<< endl;

    cout << "Tamano del archivo binario: "
        << filesystem::file_size("Alumnos.bin")<< endl;

    return 0;
}
