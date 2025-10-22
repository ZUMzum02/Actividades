#include <iostream>
#include <cstdlib>
using namespace std;

int suma(int* ptr, int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += ptr[i]; // acceso correcto
    }
    return suma;
}

int suma_recursiva(int* ptr, int tam) {
    if (tam == 0) {
        return 0;
    } else {
        return ptr[0] + suma_recursiva(ptr + 1, tam - 1);
    }
}

void ordenarAsc(char* arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (*(arr + j) > *(arr + j + 1))
                swap(*(arr + j), *(arr + j + 1));
}

int main() {
    int tam = 5;
    int* ptr = new int[tam];


    for (int i = 0; i < tam; i++) {
        ptr[i] = i;
    }

    cout << "Suma iterativa: " << suma(ptr, tam) << endl;
    cout << "Suma recursiva: " << suma_recursiva(ptr, tam) << endl;

    delete[] ptr; // Liberar memoria

// insertion, mergesort, quicksort
    return 0;
}
