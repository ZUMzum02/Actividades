#include <iostream>
using namespace std;

// Función para combinar (merge) dos subarreglos
void merge(int* arr, int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    // Crear arreglos temporales
    int* L = new int[n1];
    int* R = new int[n2];

    // Copiar datos a arreglos temporales
    for (int i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[medio + 1 + j];

    int i = 0, j = 0, k = inicio;

    // Combinar los arreglos temporales de nuevo en arr[inicio..fin]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Liberar memoria
    delete[] L;
    delete[] R;
}

// Función principal de MergeSort
void mergeSort(int* arr, int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        // Ordenar recursivamente ambas mitades
        mergeSort(arr, inicio, medio);
        mergeSort(arr, medio + 1, fin);

        // Combinar las mitades
        merge(arr, inicio, medio, fin);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

