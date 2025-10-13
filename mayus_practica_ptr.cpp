#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 8;

// -------------------- FUNCIONES --------------------

// Genera un caracter aleatorio
char caracterAleatorio() {
    int tipo = rand() % 3;
    if (tipo == 0) return 'a' + rand() % 26;
    if (tipo == 1) return 'A' + rand() % 26;
    return '0' + rand() % 10;
}

// Llena la matriz con caracteres aleatorios (usando punteros)
void llenarMatriz(char *mat) {
    for (int i = 0; i < N * N; i++)
        *(mat + i) = caracterAleatorio();
}

// Muestra matriz (punteros)
void mostrarMatriz(char *mat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << *(mat + i * N + j) << " ";
        cout << endl;
    }
}

// Clasifica en tres grupos usando punteros
void clasificarCaracteres(char *mat, char *minus, char *mayus, char *nums,
                          int &cm, int &cM, int &cn) {
    cm = cM = cn = 0;
    for (int i = 0; i < N * N; i++) {
        char c = *(mat + i);
        if (c >= 'a' && c <= 'z') *(minus + cm++) = c;
        else if (c >= 'A' && c <= 'Z') *(mayus + cM++) = c;
        else if (c >= '0' && c <= '9') *(nums + cn++) = c;
    }
}

// Ordenamiento burbuja ascendente con punteros
void ordenarAsc(char *arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (*(arr + j) > *(arr + j + 1))
                swap(*(arr + j), *(arr + j + 1));
}

// Ordenamiento burbuja descendente con punteros
void ordenarDesc(char *arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (*(arr + j) < *(arr + j + 1))
                swap(*(arr + j), *(arr + j + 1));
}

// Reconstruye matriz final con punteros
void reconstruirMatriz(char *mat, char *minus, char *mayus, char *nums,
                       int cm, int cM, int cn) {
    int idx = 0;
    for (int i = 0; i < cm; i++) *(mat + idx++) = *(minus + i);
    for (int i = 0; i < cM; i++) *(mat + idx++) = *(mayus + i);
    for (int i = 0; i < cn; i++) *(mat + idx++) = *(nums + i);
}

// -------------------- MAIN --------------------
int main() {
    srand(1);

    char matriz[N][N];
    char minus[64], mayus[64], nums[64];
    int cm, cM, cn;

    llenarMatriz(&matriz[0][0]);

    cout << "MATRIZ ORIGINAL:\n";
    mostrarMatriz(&matriz[0][0]);

    clasificarCaracteres(&matriz[0][0], minus, mayus, nums, cm, cM, cn);

    ordenarAsc(minus, cm);
    ordenarDesc(mayus, cM);
    ordenarAsc(nums, cn);

    reconstruirMatriz(&matriz[0][0], minus, mayus, nums, cm, cM, cn);

    cout << "\nMATRIZ ORDENADA:\n";
    mostrarMatriz(&matriz[0][0]);

    return 0;
}

