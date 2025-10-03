#include <iostream>
#include <string>
using namespace std;

    void imprimir(int *arr, int tam){
    for(int i =0;i < tam; i++, arr++){
        cout << *arr << " ";
        }
    }
    void intercambiar(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    }

    void invertir_array (int* arr, int tam){  // funcion para invertir los valores del array
        for(int i=0; i< tam/2; i++){
            intercambiar(&arr[i], &arr[tam-1-i]);
        }
    }
    void invertir_array_recursion(int* arr, int tam, int i=0){
        if ( i == tam/2){
                return;}
        else{
            intercambiar(&arr[i], &arr[tam-1-i]);
            invertir_array_recursion(arr,tam,i+1);
        }
    }
int main(){

    int arr[] = {1,2,3,4,5};
    int* ptr = arr;
    int tam = sizeof(arr) / sizeof(arr[0]);

    while (ptr < arr+5){
        cout << *ptr << "  ";
        ptr++;
    }
    cout << endl;
    int* ptr2 = arr+4;
    while(ptr2 >= arr){
        cout << *ptr2 << "  ";
        ptr2--;
    }
    cout << endl << "---------- INTERCAMBIO CON PUNTEROS --------- " << endl;

    int x = 10, y = 20;
    cout << "x: " << x << "  " << "y: " << y << endl;
    intercambiar(&x , &y);
    cout << "x: " << x << "  " << "y: " << y << endl;

    cout << "------------------- INVERSION DE ARRAY-------------" << endl;
    invertir_array(arr,tam);
    imprimir(arr,tam);
    cout << endl << "---------- INVERSION CON RECURSIVIDAD ---------" << endl;
    invertir_array_recursion(arr,tam);
    imprimir(arr,tam);
    return 0;}
