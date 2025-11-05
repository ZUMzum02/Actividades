#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray() {
        data = nullptr;
        size = 0;
    }

    DynamicArray(int arr[], int siz) {
        size = siz;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = arr[i];
        }
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
    }

    int get_size() const {
        return size;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1)
                cout << ", ";
        }
        cout << endl;
    }

    void push_back(int elemento) {
        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        temp[size] = elemento;

        delete[] data;

        data = temp;
        size++;
    }
};

int main() {
    int valores[] = {1, 3, 4, 5};
    DynamicArray arr(valores, 4);

    cout << "El arreglo contiene: ";
    arr.print();
    cout << "Tamaño: " << arr.get_size() << endl;

    arr.push_back(10);
    cout << "Después de push_back(10): ";
    arr.print();
    cout << "Nuevo tamaño: " << arr.get_size() << endl;

    return 0;
}
