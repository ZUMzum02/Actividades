#include <iostream>
#include <cstdlib>
using namespace std;

const int N2 = 10;

// -------------------- FUNCIONES --------------------

bool esPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// Llenar matriz (punteros)
void llenarMatriz(int *mat) {
    for (int i = 0; i < N2 * N2; i++)
        *(mat + i) = rand() % 101;
}

// Mostrar matriz (punteros)
void mostrarMatriz(int *mat) {
    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < N2; j++)
            cout << *(mat + i * N2 + j) << "\t";
        cout << endl;
    }
}

// Clasificar primos y no primos (punteros)
void clasificarPrimos(int *mat, int *primos, int *nop, int &cp, int &cnp) {
    cp = cnp = 0;
    for (int i = 0; i < N2 * N2; i++) {
        int valor = *(mat + i);
        if (esPrimo(valor)) *(primos + cp++) = valor;
        else *(nop + cnp++) = valor;
    }
}

// Ordenar descendente (punteros)
void ordenarDesc(int *arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (*(arr + j) < *(arr + j + 1))
                swap(*(arr + j), *(arr + j + 1));
}

// Reconstruir matriz con punteros
void reconstruirMatriz(int *mat, int *primos, int *nop, int cp, int cnp) {
    int idx = 0;
    for (int i = 0; i < cp; i++) *(mat + idx++) = *(primos + i);
    for (int i = 0; i < cnp; i++) *(mat + idx++) = *(nop + i);
}

// -------------------- MAIN --------------------
int main() {
    srand(1);

    int matriz[N2][N2];
    int primos[100], noPrimos[100];
    int cp, cnp;

    llenarMatriz(&matriz[0][0]);

    cout << "MATRIZ ORIGINAL:\n";
    mostrarMatriz(&matriz[0][0]);

    clasificarPrimos(&matriz[0][0], primos, noPrimos, cp, cnp);

    ordenarDesc(primos, cp);
    ordenarDesc(noPrimos, cnp);

    reconstruirMatriz(&matriz[0][0], primos, noPrimos, cp, cnp);

    cout << "\nMATRIZ FINAL (Primos primero, ambos descendentes):\n";
    mostrarMatriz(&matriz[0][0]);

    return 0;
}

