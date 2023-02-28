#include <iostream>
#include <conio.h>
using namespace std;


void addElement(int*&ptr, int element, int &size) {
    // Create the new array with an extra space
    int* aux = new int[size + 1];
    // Pass the elements
    for (int i = 0; i < size; i++) {
        aux[i] = ptr[i];
    }
    // Asign the new element
    aux[size] = element;
    // Deallocate memory
    delete[] ptr;
    // Pass the array
    ptr = aux;
    // Increment size
    size++;
}
void deleteBack(int*& ptr, int& size) {
    int* aux = new int[size - 1];
    for (int i = 0; i < size - 1; i++) {
        aux[i] = ptr[i];
    }
    size--;
    delete[] ptr;
    ptr = aux;
}
void deleteFront(int*& ptr, int& size) {
    int* aux = new int[size - 1];
    for (int i = 1; i < size; i++) {
        aux[i - 1] = ptr[i];
    }
    size--;
    delete[] ptr;
    ptr = aux;
}
void deletePosition(int*& ptr, int index, int& size) {
    int* aux = new int[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            aux[j] = ptr[i];
            j++;
        }
    }
    size--;
    delete[] ptr;
    ptr = aux;
}
void addFront(int*& ptr, int element, int& size) {
    int* aux = new int[size + 1];
    aux[0] = element;
    for (int i = 0; i < size; i++) {
        aux[i + 1] = ptr[i];
    }
    size++;
    delete[] ptr;
    ptr = aux;
}
void addPosition(int*& ptr, int element, int index, int& size) {
    int* aux = new int[size + 1];
    for (int i = 0; i <= index; i++) {
        if (index == i) {
            aux[index] = element;
        }
        else {
            aux[i] = ptr[i];
            
        }
    }
    for (int i = index + 1; i < size + 1; i++) {
        aux[i] = ptr[i -1];
    }
    size++;
    delete[] ptr;
    ptr = aux;

}
void showElements(int* ptr, int size) {
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main() {
    int* ptr = NULL;
    int option, size = 0, element, index;
    do {
        system("cls");
        cout << "\t Menu" << endl;
        cout << "1) Push back" << endl;
        cout << "2) Show" << endl;
        cout << "3) Delete back" << endl;
        cout << "4) Delete front" << endl;
        cout << "5) Delete in position" << endl;
        cout << "6) Push front" << endl;
        cout << "7) Add in position" << endl;
        cout << "8) Exit" << endl;
        cout << "Enter an option: ";
        cin >> option;
        if (option == 1) {
            cout << "New element: ";
            cin >> element;
            addElement(ptr, element, size);
            cout << "Added correctly!" << endl;
            _getch();
        }
        else if (option == 2) {
            if (size == 0) {
                cout << "There are not elements to show" << endl;
            }
            else {
                showElements(ptr, size);
            }
            _getch();
        }
        else if (option == 3) {
            if (size == 0) {
                cout << "That's not posible. There are not elements" << endl;
            }
            else {
                deleteBack(ptr, size);
                cout << "Deleted correctly!" << endl;
            }
            _getch();
        }
        else if (option == 4) {
            if (size == 0) {
                cout << "That's not possible. There are not elements" << endl;
            }
            else {
                deleteFront(ptr, size);
                cout << "Deleted correctly!" << endl;
            }
            _getch();
        }
        else if (option == 5) {
            if (size == 0) {
                cout << "That's not possible. There are not elements" << endl;
            }
            else {
                do {
                    cout << "Index to delete (0-" <<size - 1 <<"): ";
                    cin >> index;
                } while (index < 0 || index >= size);

                deletePosition(ptr, index, size);
                cout << "Deleted correctly!" << endl;
            }
            _getch();
        }
        else if(option == 6){
            cout << "New element: ";
            cin >> element;
            addFront(ptr, element, size);
            cout << "Added correctly!" << endl;
            _getch();
        }
        else if (option == 7) {
            cout << "New element: ";
            cin >> element;
            cout << "Index: ";
            cin >> index;
            addPosition(ptr, element, index, size);
            cout << "Added correctly!" << endl;
            _getch();
        }
    } while (option != 8);

    delete[]ptr;
    return 0;
}
