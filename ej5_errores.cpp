#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream archivo("ArchivoInexistente.txt");

    if (!archivo.is_open())
    {
        cout << "Error: No se pudo abrir el archivo." << endl;
        cout << "Verifique que el archivo exista y que la ruta sea correcta." << endl;
    }
    else
    {
        cout << "El archivo se abrio correctamente." << endl;
    }

    cout << "\nEl programa continua ejecutandose." << endl;

    cout << "Fin del programa." << endl;

    return 0;
}
