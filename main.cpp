// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class veracidad{
    public:
    int a,b;
    veracidad(int x, int y) : a(x), b(y){} 
};


class mayor_o_igual : public veracidad{
    public:
    mayor_o_igual(int x, int y) : veracidad(x,y){}
    
    void casos(){
        
    if (a<b){
        cout << "a es mayor que b"<< endl;}
    if (a>b){
        cout << "a es menor que b" << endl;}
    if (a==b){
        cout << "a y b son iguales" << endl;}
}};

class letra{
    public:
    char a;
    letra(char x): a(x){}
    void mayuscula (){
    if ( a >= 65 && a <= 90){
        cout << " es una mayuscula" << endl;
    } else if (a >= 97 && a <= 122) {
        cout << "  es una minuscla" << endl;}
        else if ( a >=48 && a <= 57){
            cout << "es un numero" << endl;}
            else{ cout << "sabra dios" << endl;}
}};


int main(){
    mayor_o_igual* ptr1 = new mayor_o_igual(2,3);
    ptr1->casos();
    
    letra* ptr2 = new letra('&');
    ptr2->mayuscula();
}