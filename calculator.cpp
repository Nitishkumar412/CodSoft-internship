#include <iostream>
using namespace std;

void calculator() {
    cout << "Welcome to the Calculator Program!" << endl;
    cout << "Select an operation to perform:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;

    int choice;
    cout << "Enter the number corresponding to your choice (1/2/3/4): ";
    cin >> choice;

    if (choice < 1 || choice > 4) {
        cout << "Invalid choice. Please select a valid operation." << endl;
        return;
    }

    double num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    switch (choice) {
        case 1:
            cout << "The result of addition: " << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
            break;
        case 2:
            cout << "The result of subtraction: " << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
            break;
        case 3:
            cout << "The result of multiplication: " << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
            break;
        case 4:
            if (num2 != 0)
                cout << "The result of division: " << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
            else
                cout << "Error: Division by zero is not allowed." << endl;
            break;
    }
}

int main() {
    calculator();
    return 0;
}
