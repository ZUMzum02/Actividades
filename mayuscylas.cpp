#include <iostream>
#include <cstdlib> // rand(), srand()
using namespace std;

// Crear matriz
char** crearMatriz(int n, int m) {
    char** mat = new char*[n];
    for (int i = 0; i < n; ++i)
        mat[i] = new char[m];
    return mat;
}

// Mostrar matriz
void imprimirMatriz(char** mat, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << mat[i][j] << ' ';
        cout << '\n';
    }
}

// Clasificar matriz según cuadrantes
void clasificarMatriz(char** mat, int n, int m) {
    int mitadFilas = n / 2;
    int mitadCols = m / 2;
    int mitadDerechaSegundo = mitadCols + (mitadCols / 2);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Zona de mayúsculas
            if (i < mitadFilas && j < mitadDerechaSegundo)
                mat[i][j] = 'A' + rand() % 26;
            // Zona de minúsculas
            else if ((i < mitadFilas && j >= mitadDerechaSegundo) ||
                     (i >= mitadFilas && j < mitadCols))
                mat[i][j] = 'a' + rand() % 26;
            // Zona de números
            else
                mat[i][j] = '0' + rand() % 10;
        }
    }
}

// Ordenar subzona de la matriz
void ordenarSubzona(char** mat, int filaInicio, int filaFin, int colInicio, int colFin) {
    int total = (filaFin - filaInicio) * (colFin - colInicio);
    char* temp = new char[total];
    int k = 0;

    // Copiar subzona
    for (int i = filaInicio; i < filaFin; ++i)
        for (int j = colInicio; j < colFin; ++j)
            temp[k++] = mat[i][j];

    // Ordenar burbuja descendente
    for (int i = 0; i < total - 1; ++i)
        for (int j = 0; j < total - i - 1; ++j)
            if (temp[j] > temp[j + 1]) {
                char aux = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = aux;
            }

    // Volver a colocar en la subzona
    k = 0;
    for (int i = filaInicio; i < filaFin; ++i)
        for (int j = colInicio; j < colFin; ++j)
            mat[i][j] = temp[k++];

    delete[] temp;
}

int main() {
    int n, m;
    cout << "Ingrese filas (n) y columnas (m): ";
    cin >> n >> m;

    srand(1); // semilla fija

    char** matriz = crearMatriz(n, m);

    // Clasificar matriz
    clasificarMatriz(matriz, n, m);

    cout << "\nMatriz clasificada por zonas:\n";
    imprimirMatriz(matriz, n, m);

    // Calcular divisiones
    int mitadFilas = n / 2;
    int mitadCols = m / 2;
    int mitadDerechaSegundo = mitadCols + (mitadCols / 2);

    // Ordenar cada zona por separado
    // Zona 1 (mayúsculas): filas 0..mitadFilas, columnas 0..mitadDerechaSegundo
    ordenarSubzona(matriz, 0, mitadFilas, 0, mitadDerechaSegundo);

    // Zona 2 (minúsculas): parte superior derecha y parte inferior izquierda
    ordenarSubzona(matriz, 0, mitadFilas, mitadDerechaSegundo, m);
    ordenarSubzona(matriz, mitadFilas, n, 0, mitadCols);

    // Zona 3 (números): parte inferior derecha
    ordenarSubzona(matriz, mitadFilas, n, mitadCols, m);

    cout << "\nMatriz ordenada dentro de cada zona:\n";
    imprimirMatriz(matriz, n, m);

    // Liberar memoria
    for (int i = 0; i < n; ++i)
        delete[] matriz[i];
    delete[] matriz;

    return 0;
}

