#include <iostream>
using namespace std;

// 1️⃣ Intercambio de valores con punteros
void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 2️⃣ Copiar cadena (sin recursión)
void copiarCadena(char *dest, const char *orig) {
    while (*orig != '\0') {
        *dest = *orig;
        dest++;
        orig++;
    }
    *dest = '\0';
}

// 3️⃣ Copiar cadena (recursiva)
void copiarCadenaRec(char *dest, const char *orig) {
    *dest = *orig;
    if (*orig == '\0') return;
    copiarCadenaRec(dest + 1, orig + 1);
}

// 4️⃣ Calcular longitud de una cadena (sin recursión)
int longitudCadena(const char *cad) {
    int len = 0;
    while (*cad != '\0') {
        len++;
        cad++;
    }
    return len;
}

// 5️⃣ Calcular longitud de una cadena (recursiva)
int longitudCadenaRec(const char *cad) {
    if (*cad == '\0') return 0;
    return 1 + longitudCadenaRec(cad + 1);
}

// 6️⃣ Mostrar arreglo usando punteros
void mostrarArreglo(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

// 7️⃣ Mostrar arreglo recursivamente
void mostrarArregloRec(int *arr, int n) {
    if (n == 0) return;
    cout << *arr << " ";
    mostrarArregloRec(arr + 1, n - 1);
}

// 8️⃣ Sumar todos los elementos de un arreglo (punteros)
int sumarArreglo(int *arr, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++)
        suma += *(arr + i);
    return suma;
}

// 9️⃣ Sumar todos los elementos recursivamente
int sumarArregloRec(int *arr, int n) {
    if (n == 0) return 0;
    return *arr + sumarArregloRec(arr + 1, n - 1);
}

// 🔟 Invertir cadena usando punteros
void invertirCadena(char *cad) {
    int len = longitudCadena(cad);
    for (int i = 0; i < len / 2; i++) {
        char temp = *(cad + i);
        *(cad + i) = *(cad + len - 1 - i);
        *(cad + len - 1 - i) = temp;
    }
}

int main() {
    // Ejemplo de uso de algunas funciones:

    // 1. Intercambio
    int x = 5, y = 10;
    intercambiar(&x, &y);
    cout << "x=" << x << " y=" << y << endl;

    // 2. Copiar cadena
    char origen[] = "Hola";
    char destino[20];
    copiarCadena(destino, origen);
    cout << "Cadena copiada: " << destino << endl;

    // 3. Longitud recursiva
    cout << "Longitud: " << longitudCadenaRec(destino) << endl;

    // 4. Mostrar arreglo
    int numeros[] = {1, 2, 3, 4, 5};
    mostrarArregloRec(numeros, 5);
    cout << "Suma recursiva: " << sumarArregloRec(numeros, 5) << endl;

    // 5. Invertir cadena
    invertirCadena(destino);
    cout << "Invertida: " << destino << endl;

    return 0;
}
