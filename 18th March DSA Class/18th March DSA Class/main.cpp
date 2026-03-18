#include "myStack.h"
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;
    myStack<int> s(size);
    int choice, value;
    do {
        cout << endl << "1. Push" << endl << "2. Pop" << endl << "3. Top" << endl << "4. Display" << endl << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            cout << "Popped: " << s.pop() << endl;
            break;
        case 3:
            cout << "Top: " << s.top() << endl;
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
    return 0;
}
