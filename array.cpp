#include <iostream>
using namespace std;

// Función para intercambiar dos valores
void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Suma recursiva de un arreglo
long sumar(int arr[], int tam) {
    if (tam <= 0)
        return 0;
    return arr[tam - 1] + sumar(arr, tam - 1);
}

// Imprimir arreglo
void imprimir(int arr[], int tam) {
    cout << "array: ";
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Imprimir arreglo en orden inverso (sin modificarlo)
void imprimir_invertido(int arr[], int tam) {
    cout << "array invertido: ";
    for (int i = tam - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Invertir arreglo en su lugar (forma iterativa)
void invertir(int arr[], int tam) {
    for (int i = 0; i < tam / 2; i++) {
        intercambiar(arr[i], arr[tam - i - 1]);
    }
}

// Invertir arreglo con recursividad
void r_invertir(int arr[], int tam, int i = 0) {
    if (i >= tam / 2)
        return;
    intercambiar(arr[i], arr[tam - i - 1]);
    r_invertir(arr, tam, i + 1);
}

int main() {
    int array[3] = {2, 3, 4};

    imprimir(array, 3);
    imprimir_invertido(array, 3);

    cout << "Invirtiendo con recursividad..." << endl;
    r_invertir(array, 3);
    imprimir(array, 3);

    cout << "Suma del arreglo: " << sumar(array, 3) << endl;

    return 0;
}
