#include <iostream>
using namespace std;

class Cadena {
private:
    char* texto;     // puntero para almacenar la cadena
    int longitud;    // longitud de la cadena

public:
    // Constructor por defecto
    Cadena() {
        texto = nullptr;
        longitud = 0;
    }

    // Constructor con parámetro
    Cadena(const char* cadena) {
        longitud = 0;
        while (cadena[longitud] != '\0') { // calcular longitud
            longitud++;
        }

        texto = new char[longitud + 1];
        for (int i = 0; i < longitud; i++) {
            texto[i] = cadena[i];
        }
        texto[longitud] = '\0';
    }

    // Destructor
    ~Cadena() {
        delete[] texto;
    }

    // Mostrar cadena
    void mostrar() const {
        if (texto)
            cout << texto;
        else
            cout << "(cadena vacía)";
    }

    // Obtener longitud
    int getLongitud() const {
        return longitud;
    }

    // Copiar otra cadena
    void copiar(const Cadena& otra) {
        delete[] texto;
        longitud = otra.longitud;
        texto = new char[longitud + 1];
        for (int i = 0; i < longitud; i++) {
            texto[i] = otra.texto[i];
        }
        texto[longitud] = '\0';
    }

    // Concatenar otra cadena
    void concatenar(const Cadena& otra) {
        char* nuevo = new char[longitud + otra.longitud + 1];
        for (int i = 0; i < longitud; i++) {
            nuevo[i] = texto[i];
        }
        for (int j = 0; j < otra.longitud; j++) {
            nuevo[longitud + j] = otra.texto[j];
        }
        nuevo[longitud + otra.longitud] = '\0';

        delete[] texto;
        texto = nuevo;
        longitud += otra.longitud;
    }
};

int main() {
    Cadena palabra1("Hola");
    Cadena palabra2(" Mundo");

    cout << "Palabra 1: ";
    palabra1.mostrar();
    cout << endl;

    cout << "Palabra 2: ";
    palabra2.mostrar();
    cout << endl;

    palabra1.concatenar(palabra2);
    cout << "Concatenadas: ";
    palabra1.mostrar();
    cout << endl;

    cout << "Longitud total: " << palabra1.getLongitud() << endl;

    return 0;
}
