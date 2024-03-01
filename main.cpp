#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Función para crear un archivo
void crearArchivo(string nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        cout << "Archivo " << nombreArchivo << " creado exitosamente." << endl;
    } else {
        cout << "Error al crear el archivo." << endl;
    }
    archivo.close();
}

// Función para editar un archivo
void editarArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        vector<string> lineas;
        string linea;
        while (getline(archivo, linea)) {
            lineas.push_back(linea);
        }
        archivo.close();

        // Mostrar el contenido del archivo
        for (string linea : lineas) {
            cout << linea << endl;
        }

        // Editar el contenido del archivo
        cout << "Introduzca las nuevas lineas del archivo (termina con una linea vacia):" << endl;
        lineas.clear();
        while (getline(cin, linea)) {
            if (linea.empty()) {
                break;
            }
            lineas.push_back(linea);
        }

        // Sobrescribir el archivo con el nuevo contenido
        ofstream archivoSalida(nombreArchivo);
        for (string linea : lineas) {
            archivoSalida << linea << endl;
        }
        archivoSalida.close();

        cout << "Archivo " << nombreArchivo << " editado exitosamente." << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

// Función para eliminar un archivo
void eliminarArchivo(string nombreArchivo) {
    if (remove(nombreArchivo.c_str()) == 0) {
        cout << "Archivo" << nombreArchivo << "eliminado exitosamente." << endl;
    } else {
        cout << "Error al eliminar el archivo." << endl;
    }
}

// Función para mostrar información del archivo
void mostrarInformacionArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        cout << "Nombre: " << nombreArchivo << endl;
        cout << "Tamaño: " << archivo.tellg() << " bytes" << endl;

        // Mostrar las prímeras líneas del archivo
        cout << "Primeras líneas:" << endl;
        string linea;
        for (int i = 0; i < 5; i++) {
            if (getline(archivo, linea)) {
                cout << linea << endl;
            } else {
                break;
            }
        }

        archivo.close();
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

int main() {
    int opcion;
    string nombreArchivo;

    while (true) {
        cout << "**Menu de gestion de archivos**" << endl;
        cout << "1. Crear archivo" << endl;
        cout << "2. Editar archivo" << endl;
        cout << "3. Eliminar archivo" << endl;
        cout << "4. Mostrar informacion del archivo" << endl;
        cout << "5. Salir" << endl;
        cout << "Introduzca una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Introduzca el nombre del archivo a crear: ";
                cin >> nombreArchivo;
                crearArchivo(nombreArchivo);
                break;
            case 2:
                cout << "Introduzca el nombre del archivo a editar: ";
                cin >> nombreArchivo;
                editarArchivo(nombreArchivo);
                break;
            case 3:
                cout << "Introduzca el nombre del archivo a editar: ";
                cin >> nombreArchivo;
                eliminarArchivo(nombreArchivo);
                break;
            case 4:
                cout << "Introduzca el nombre del archivo a mostrar información: ";
                cin >> nombreArchivo;
                mostrarInformacionArchivo(nombreArchivo);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opción no valida." << endl;
        }
    }

    return 0;
}