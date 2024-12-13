#include<iostream>
using namespace std;

int main() {
    int choice;
    cout << "Choose a program to run:\n";
    cout << "1. Print numbers in rows and columns\n";
    cout << "2. Print alphabet in rows\n";
    cout << "3. Print decreasing numbers with row adjustments\n";
    cout << "4. Print inverted numbers with spaces\n";
    cout << "5. Print increasing alphabets row-wise\n";
    cout << "6. Print lowercase alphabets in rows\n";
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    if (choice == 1) {
        int row, colnums;
        cout << "Enter the number of rows: ";
        cin >> row;
        cout << "Enter the number of columns: ";
        cin >> colnums;
        for (int j = 1; j <= colnums; j++) {
            for (int i = 1; i <= row; i++) {
                cout << i;
            }
            cout << endl;
        }
    } 
    else if (choice == 2) {
        char chart = 'A';
        for (int i = 1; i <= 24; i++) {
            cout << chart;
            chart++;
            if (i % 6 == 0)
                cout << endl;
        }
    } 
    else if (choice == 3) {
        int row, colnums;
        cout << "Enter the number of rows: ";
        cin >> row;
        cout << "Enter the number of columns: ";
        cin >> colnums;
        for (int j = 1; j <= colnums; j++) {
            row = row - (row - j);
            for (int i = 1; i <= row; i++) {
                cout << i;
            }
            cout << endl;
        }
    } 
    else if (choice == 4) {
        int row, colnums;
        cout << "Enter the number of rows: ";
        cin >> row;
        cout << "Enter the number of columns: ";
        cin >> colnums;
        for (int j = 1; j <= colnums; j++) {
            int z = 5 - j;
            row = row - (row - j);
            for (int k = 1; k <= z; k++) {
                cout << " ";
            }
            for (int i = row; i >= 1; i--) {
                cout << i;
            }
            cout << endl;
        }
    } 
    else if (choice == 5) {
        int row, colnums;
        cout << "Enter the number of rows: ";
        cin >> row;
        cout << "Enter the number of columns: ";
        cin >> colnums;
        char ch = 'A';
        for (int j = 1; j <= colnums; j++) {
            for (int i = 1; i <= j; i++) {
                cout << ch << " ";
                ++ch;
            }
            cout << endl;
            ch = 'A';
        }
    } 
    else if (choice == 6) {
        int row, colnums;
        cout << "Enter the number of rows: ";
        cin >> row;
        cout << "Enter the number of columns: ";
        cin >> colnums;
        char ch = 'a';
        for (int j = 1; j <= colnums; j++) {
            for (int i = 1; i <= row; i++) {
                cout << ch;
                ++ch;
            }
            cout << endl;
            ch = 'a';
        }
    } 
    else {
        cout << "Invalid choice. Please run the program again.\n";
    }

    return 0;
}
