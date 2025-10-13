#include <iostream>
#include <cstdlib>
using namespace std;

// ───────────────────────────────
// 1️⃣ Crear matriz dinámica n x m
// ───────────────────────────────
int **crearMatriz(int n, int m) {
    int **mat = new int*[n];
    for (int i = 0; i < n; i++)
        mat[i] = new int[m];
    return mat;
}

// ───────────────────────────────
// 2️⃣ Liberar memoria de la matriz
// ───────────────────────────────
void liberarMatriz(int **mat, int n) {
    for (int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;
}

// ───────────────────────────────
// 3️⃣ Llenar matriz con valores aleatorios
// ───────────────────────────────
void llenarMatriz(int **mat, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] = rand() % 10;  // valores entre 0 y 9
}

// ───────────────────────────────
// 4️⃣ Mostrar matriz (normal)
// ───────────────────────────────
void mostrarMatriz(int **mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

// ───────────────────────────────
// 5️⃣ Mostrar matriz recursivamente
// ───────────────────────────────
void mostrarMatrizRec(int **mat, int n, int m, int i = 0, int j = 0) {
    if (i == n) return; // caso base: fin de filas
    cout << mat[i][j] << " ";
    if (j == m - 1) {
        cout << endl;
        mostrarMatrizRec(mat, n, m, i + 1, 0);
    } else {
        mostrarMatrizRec(mat, n, m, i, j + 1);
    }
}

// ───────────────────────────────
// 6️⃣ Sumar todos los elementos
// ───────────────────────────────
int sumarMatriz(int **mat, int n, int m) {
    int suma = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            suma += mat[i][j];
    return suma;
}

// ───────────────────────────────
// 7️⃣ Buscar valor máximo
// ───────────────────────────────
int maxMatriz(int **mat, int n, int m) {
    int max = mat[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] > max)
                max = mat[i][j];
    return max;
}

// ───────────────────────────────
// 8️⃣ Intercambiar dos filas
// ───────────────────────────────
void intercambiarFilas(int **mat, int f1, int f2) {
    int *temp = mat[f1];
    mat[f1] = mat[f2];
    mat[f2] = temp;
}

// ───────────────────────────────
// 9️⃣ Calcular suma por filas (devuelve arreglo)
// ───────────────────────────────
int *sumarFilas(int **mat, int n, int m) {
    int *res = new int[n];
    for (int i = 0; i < n; i++) {
        res[i] = 0;
        for (int j = 0; j < m; j++)
            res[i] += mat[i][j];
    }
    return res;
}

// ───────────────────────────────
// 🔟 Transpuesta de la matriz
// ───────────────────────────────
int **transpuesta(int **mat, int n, int m) {
    int **T = crearMatriz(m, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            T[j][i] = mat[i][j];
    return T;
}

// ───────────────────────────────
// 1️⃣1️⃣ Multiplicar dos matrices dinámicas
// ───────────────────────────────
int **multiplicar(int **A, int **B, int n, int p, int m) {
    int **C = crearMatriz(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            C[i][j] = 0;
            for (int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}

// ───────────────────────────────
// FUNCION PRINCIPAL (demostración)
// ───────────────────────────────
int main() {
    srand(1); // semilla fija para resultados reproducibles

    int n = 3, m = 4;
    cout << "Creando matriz " << n << "x" << m << endl;

    int **mat = crearMatriz(n, m);
    llenarMatriz(mat, n, m);

    cout << "\nMatriz original:" << endl;
    mostrarMatriz(mat, n, m);

    cout << "\nSuma total: " << sumarMatriz(mat, n, m) << endl;
    cout << "Valor maximo: " << maxMatriz(mat, n, m) << endl;

    cout << "\nIntercambiando fila 0 y fila 2:" << endl;
    intercambiarFilas(mat, 0, 2);
    mostrarMatriz(mat, n, m);

    cout << "\nSuma por filas:" << endl;
    int *sumaFilas = sumarFilas(mat, n, m);
    for (int i = 0; i < n; i++)
        cout << "Fila " << i << ": " << sumaFilas[i] << endl;
    delete[] sumaFilas;

    cout << "\nMatriz transpuesta:" << endl;
    int **T = transpuesta(mat, n, m);
    mostrarMatriz(T, m, n);

    cout << "\nMostrando recursivamente:" << endl;
    mostrarMatrizRec(mat, n, m);

    liberarMatriz(mat, n);
    liberarMatriz(T, m);

    cout << "\nMemoria liberada correctamente." << endl;
    return 0;
}
