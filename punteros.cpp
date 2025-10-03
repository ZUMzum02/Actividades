#include <iostream>
#include <string>
using namespace std;
int main()
{
  cout << "----------- CASO 1 -------- " << endl;
  int* ptr;
  int x;
  x=10;
  ptr = &x;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << &ptr << endl;
    cout << "-------- CASO 2 ---------" << endl;

  int y{20};
  ptr = &y;
  cout << ptr << endl;
    cout << *ptr << endl;
    cout << &ptr << endl;
    cout << "--------- CLASICA IGUALDAD DE DIRECCIONES --------" << endl;
int* ptr2;
ptr2 = &y;
if (ptr == ptr2) cout << "tienen el mismo valor" << endl;

cout << "------------- CASO 3: CAMBIO DE VALOR CON PUNTEROS-------------" << endl;
 int* ptr3;
 int z{11};
 ptr3 = &z;
 cout << ptr3 << endl;
 *ptr3 = 1111;
 cout << z;
 cout << "------------ CASO 4: DIRECCIONES DE ARRAY-------------" << endl;
 int arr[]={1,2,3,4,5};
 cout << arr << endl; // imprime la misma direccion de arr[0];
 cout << &arr[0] << endl;
 cout << &arr[1] << endl; // se le +4 por cada tipo entero del array
 cout << &arr[2] << endl; // +4
 cout << &arr[3] << endl; // +4
 cout <<  "------------ CASO 4: DIRECCIONES DE ARRAY-------------" << endl;
 int* ptr4 = arr;
 cout << *ptr4 << endl;
 ptr4++; cout << *ptr4 << endl; // imprime el siguiente elemento del array

 *ptr4 = *ptr4 + 20; // se le suma pero al arr[1] ya que le sumaste ++ a su direccion line 43
 cout << arr[0] << endl;
 cout << arr[1];

}

