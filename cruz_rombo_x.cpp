#include <iostream>
using namespace std;

// Crear matriz n x m y llenar con '-'
char** crearMatriz(int n, int m) {
    char** mat = new char*[n];
    for (int i = 0; i < n; ++i) {
        mat[i] = new char[m];
        for (int j = 0; j < m; ++j) mat[i][j] = '-';
    }
    return mat;
}

// Imprimir matriz
void imprimirMatriz(char** mat, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }
}

// Liberar memoria
void liberarMatriz(char** mat, int n) {
    for (int i = 0; i < n; ++i) delete[] mat[i];
    delete[] mat;
}

// Dibujar rombo (diamante) centrado; usa distancia Manhattan
void dibujarRombo(char** mat, int n, int m) {
    int centerR = n / 2;
    int centerC = m / 2;
    // radio máximo que cabe en la matriz
    int radio = centerR < centerC ? centerR : centerC;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int manhattan = (i > centerR ? i - centerR : centerR - i)
                          + (j > centerC ? j - centerC : centerC - j);
            if (manhattan <= radio) mat[i][j] = 'i';
        }
    }
}

// Dibujar cruz "más" (horizontal + vertical en el centro)
void dibujarCruzMas(char** mat, int n, int m) {
    int centerR = n / 2;
    int centerC = m / 2;
    for (int j = 0; j < m; ++j) mat[centerR][j] = 'i';
    for (int i = 0; i < n; ++i) mat[i][centerC] = 'i';
}

// Dibujar cruz en X (dos diagonales)
void dibujarCruzX(char** mat, int n, int m) {
    for (int i = 0; i < n; ++i) {
        int j1 = i;            // diagonal principal (i,i)
        int j2 = m - 1 - i;    // diagonal secundaria (i, m-1-i)
        if (j1 >= 0 && j1 < m) mat[i][j1] = 'i';
        if (j2 >= 0 && j2 < m) mat[i][j2] = 'i';
    }
}

int main() {
    int n, m;
    cout << "Ingrese filas (n) y columnas (m) separadas por espacio: ";
    if (!(cin >> n >> m) || n <= 0 || m <= 0) {
        cout << "Entrada invalida. n y m deben ser enteros positivos.\n";
        return 1;
    }

    cout << "Elija una opcion:\n";
    cout << "1 - Rombo (diamante centrado)\n";
    cout << "2 - Cruz '+' (horizontal y vertical en el centro)\n";
    cout << "3 - Cruz 'X' (diagonales)\n";
    cout << "Opcion: ";
    int opcion;
    if (!(cin >> opcion)) opcion = 1;

    char** matriz = crearMatriz(n, m);

    switch (opcion) {
        case 1:
            dibujarRombo(matriz, n, m);
            break;
        case 2:
            dibujarCruzMas(matriz, n, m);
            break;
        case 3:
            dibujarCruzX(matriz, n, m);
            break;
        default:
            cout << "Opcion no valida, se dibujara el rombo por defecto.\n";
            dibujarRombo(matriz, n, m);
    }

    cout << "\nResultado:\n";
    imprimirMatriz(matriz, n, m);

    liberarMatriz(matriz, n);
    return 0;
}
