#include <iostream>
using namespace std;

int main() {
    int choice;
    cout << "Choose a program to run:\n";
    cout << "1. Print alphabet grid\n";
    cout << "2. Print decreasing stars\n";
    cout << "3. Print hollow rectangle\n";
    cout << "4. Print inverted hollow triangle\n";
    cout << "5. Print right-aligned triangle\n";
    cout << "6. Print inverted right-aligned triangle\n";
    cout << "7. Print hollow right-aligned triangle\n";
    cout << "Enter your choice (1-7): ";
    cin >> choice;

    if (choice == 1) {
        for (char i = 'a'; i <= 'e'; i++) {
            for (char j = 'a'; j <= 'e'; j++) {
                cout << j << " ";
            }
            cout << endl;
        }
    } else if (choice == 2) {
        int n = 6;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= (n - i); j++) {
                cout << "* ";
            }
            cout << endl;
        }
    } else if (choice == 3) {
        int n = 7;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 1 || i == n || j == 0 || j == n) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    } else if (choice == 4) {
        int n = 6;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= (n - i); j++) {
                if (i == 1 || j == (n - i) || j == 0) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    } else if (choice == 5) {
        int n = 6;
        for (int i = 1; i <= n; i++) {
            for (int k = n - i; k > 0; k--) {
                cout << " ";
            }
            for (int j = 1; j <= i; j++) {
                cout << "* ";
            }
            cout << endl;
        }
    } else if (choice == 6) {
        int n = 6;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= i - 1; k++) {
                cout << " ";
            }
            for (int j = i; j <= n; j++) {
                cout << "* ";
            }
            cout << endl;
        }
    } else if (choice == 7) {
        int n = 6;
        for (int i = 1; i <= n; i++) {
            for (int k = n - i; k > 0; k--) {
                cout << " ";
            }
            for (int j = 1; j <= i; j++) {
                if (i == n || j == i || j == 1) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "Invalid choice. Please run the program again.\n";
    }

    return 0;
}
