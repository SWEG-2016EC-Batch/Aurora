#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <string>
#include <algorithm>  
using namespace std;

// Function declarations
int update_stock();
int search_medicine();
int daily_report();
int view_history();
int customer_service();
const int passwordof_staff = 232425;

int customer_service() {
    cout << " Thank you for choosing 5S Virtual Pharmacy.\n";

    string name, hospital_name;
    int age;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter hospital name: ";
    getline(cin, hospital_name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore(); // Clear leftover newline

    string medicine, genericSearch;
    cout << "Please enter the medicine that you want (Medicine name): ";
    getline(cin, medicine);
    cout << "Enter the generic name you want to search: ";
    getline(cin, genericSearch);

    ifstream file("pharmacy.txt");
    if (!file) {
        cout << " File not found! Make sure pharmacy.txt is in the correct folder.\n";
        return 1;
    }

    ofstream fout("prescription.txt", ios::app);
    if (!fout) {
        cout << " Failed to open prescription.txt\n";
        return 1;
    }

    string line;
    bool found = false;

    // Table Header
    cout << "\n" << string(115, '=') << "\n";
    cout << "| " << left << setw(18) << "Medicine Name"
         << "| " << setw(10) << "Price ($)"
         << "| " << setw(10) << "Quantity"
         << "| " << setw(15) << "Expiry Date"
         << "| " << setw(20) << "Country of Origin"
         << "| " << setw(25) << "Generic Name" << "|\n";
    cout << string(115, '-') << "\n";

    time_t now = time(0);             
    char* dt = ctime(&now);           

    while (getline(file, line)) {
        stringstream ss(line);
        string medName, price, quantity, expiry, country, generic;

        getline(ss, medName, '|');
        getline(ss, price, '|');
        getline(ss, quantity, '|');
        getline(ss, expiry, '|');
        getline(ss, country, '|');
        getline(ss, generic, '|');

        if (generic == genericSearch) {
            cout << "| " << left << setw(18) << medName
                 << "| " << setw(10) << price
                 << "| " << setw(10) << quantity
                 << "| " << setw(15) << expiry
                 << "| " << setw(20) << country
                 << "| " << setw(25) << generic << "|\n";

            found = true;
            fout << name << "," << hospital_name << "," << age << "," << dt << "," 
                 << medName << "," << price << "," << quantity << "," << expiry 
                 << "," << country << "," << generic << "\n";
        }
    }

    cout << string(115, '=') << "\n";

    if (!found) {
        cout << " No medicines found with the generic name: " << genericSearch << "\n";
    }

    fout.close();
    file.close();

    char buy;
    string location;
buy_prompt:
    cout << "Do you want to buy it? (Y/n): ";
    cin >> buy;
    cin.ignore();

    if (buy == 'Y' || buy == 'y') {
        cout << "Enter your address with your phone number, please: ";
        getline(cin, location);
        cout << "Your medicine will arrive soon. Thank you for choosing 5S Pharmacy.\n";
    } else if (buy == 'n' || buy == 'N') {
        cout << "Order cancelled. Have a good day!\n";
    } else {
        cout << "Invalid input.\n";
        goto buy_prompt;
    }

    return 0;
}

int update_stock() {
    int choice;

    cout << "Do you want to:\n";
    cout << "1. See expired medicines\n";
    cout << "2. Add new medicine\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        ifstream file("pharmacy.txt");
        if (!file) {
            cerr << " Could not open pharmacy.txt\n";
            return 1;
        }

        string line;
        time_t now = time(0);
        tm *ltm_now = localtime(&now);

        while (getline(file, line)) {
            stringstream ss(line);
            string medName, price, quantity, expiry, country, generic;

            getline(ss, medName, '|');
            getline(ss, price, '|');
            getline(ss, quantity, '|');
            getline(ss, expiry, '|');
            getline(ss, country, '|');
            getline(ss, generic, '|');

            expiry.erase(0, expiry.find_first_not_of(" \t"));
            expiry.erase(expiry.find_last_not_of(" \t") + 1);

            int y, m, d;
            if (sscanf(expiry.c_str(), "%d-%d-%d", &y, &m, &d) == 3) {
                tm expiry_tm = {};
                expiry_tm.tm_year = y - 1900;
                expiry_tm.tm_mon = m - 1;
                expiry_tm.tm_mday = d;

                time_t expiry_time = mktime(&expiry_tm);
                time_t today = mktime(ltm_now);

                if (difftime(expiry_time, today) < 0) {
                    cout << "⚠️ Medicine \"" << medName << "\" is expired (Expiry: " << expiry << "). Please update it.\n";
                }
            }
        }

        file.close();
    } else if (choice == 2) {
        string medName, price, quantity, expiry, country, generic;

        cout << "Enter Medicine Name: ";
        getline(cin, medName);
        cout << "Enter Price: ";
        getline(cin, price);
        cout << "Enter Quantity: ";
        getline(cin, quantity);
        cout << "Enter Expiry Date (YYYY-MM-DD): ";
        getline(cin, expiry);
        cout << "Enter Country of Origin: ";
        getline(cin, country);
        cout << "Enter Generic Name: ";
        getline(cin, generic);

        ofstream fout("pharmacy.txt", ios::app);
        if (!fout) {
            cerr << " Error opening pharmacy.txt for writing!\n";
            return 1;
        }

        fout << medName << " | " << price << " | " << quantity << " | " << expiry
             << " | " << country << " | " << generic << "\n";
        fout.close();

        cout << "Medicine added successfully.\n";
    } else {
        cout << " Invalid input. Please enter 1 or 2 only.\n";
    }

    return 0;
}

int search_medicine() {
    string medicine;
    cout << "Enter medicine generic name you want to search: ";
    getline(cin, medicine);

    ifstream file("pharmacy.txt");
    if (!file) {
        cout << " File not found!\n";
        return 1;
    }

    string line;
    bool found = false;

    cout << "\n" << string(115, '=') << "\n";
    cout << "| " << left << setw(18) << "Medicine Name"
         << "| " << setw(10) << "Price ($)"
         << "| " << setw(10) << "Quantity"
         << "| " << setw(15) << "Expiry Date"
         << "| " << setw(20) << "Country of Origin"
         << "| " << setw(25) << "Generic Name" << "|\n";
    cout << string(115, '-') << "\n";

    while (getline(file, line)) {
        stringstream ss(line);
        string medName, price, quantity, expiry, country, generic;

        getline(ss, medName, '|');
        getline(ss, price, '|');
        getline(ss, quantity, '|');
        getline(ss, expiry, '|');
        getline(ss, country, '|');
        getline(ss, generic, '|');

        generic.erase(0, generic.find_first_not_of(" \t"));
        generic.erase(generic.find_last_not_of(" \t") + 1);

        if (generic == medicine) {
            cout << "| " << left << setw(18) << medName
                 << "| " << setw(10) << price
                 << "| " << setw(10) << quantity
                 << "| " << setw(15) << expiry
                 << "| " << setw(20) << country
                 << "| " << setw(25) << generic << "|\n";
            found = true;
        }
    }

    cout << string(115, '=') << "\n";

    if (!found) {
        cout << " No medicines found with the generic name: " << medicine << "\n";
    }

    file.close();
    return 0;
}

int daily_report() {
    ifstream file("prescription.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open prescription.txt\n";
        return 1;
    }

    string input_date;
    cout << "Enter the date (e.g., Sun Jun 08 02:02:22 2025): ";
    getline(cin, input_date);

    cout << "\n--- Daily Report for " << input_date << " ---\n";
    bool found = false;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string patient_name, hospital, age, date, medName, price, quantity, expiry, country, generic;

        getline(ss, patient_name, ',');
        getline(ss, hospital, ',');
        getline(ss, age, ',');
        getline(ss, date, ',');

        if (date.find(input_date) != string::npos) {
            found = true;
            getline(ss, medName, ',');
            getline(ss, price, ',');
            getline(ss, quantity, ',');
            getline(ss, expiry, ',');
            getline(ss, country, ',');
            getline(ss, generic, ',');

            cout << "Patient: " << patient_name << " | Hospital: " << hospital << " | Age: " << age << "\n";
            cout << "Medicine: " << medName << " | Price: $" << price
                 << " | Quantity: " << quantity << " | Expiry: " << expiry
                 << " | Country: " << country << " | Generic: " << generic << "\n";
            cout << "-----------------------------\n";
        }
    }

    if (!found) {
        cout << "No records found for this date.\n";
    }

    file.close();
    return 0;
}

int view_history() {
    ifstream file("prescription.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open prescription.txt\n";
        return 1;
    }

    string search_name;
    cout << "Enter customer name to view history: ";
    getline(cin, search_name);

    cout << "\n--- Purchase History for \"" << search_name << "\" ---\n";
    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, hospital, age, date, medName, price, quantity, expiry, country, generic;

        getline(ss, name, ',');
        getline(ss, hospital, ',');
        getline(ss, age, ',');
        getline(ss, date, ',');
        getline(ss, medName, ',');
        getline(ss, price, ',');
        getline(ss, quantity, ',');
        getline(ss, expiry, ',');
        getline(ss, country, ',');
        getline(ss, generic, ',');

        // Case-insensitive match (optional: remove if not needed)
        string name_lower = name, search_lower = search_name;
        transform(name_lower.begin(), name_lower.end(), name_lower.begin(), ::tolower);
        transform(search_lower.begin(), search_lower.end(), search_lower.begin(), ::tolower);

        if (name_lower == search_lower) {
            found = true;
            cout << "Date: " << date;
            cout << " | Medicine: " << medName
                 << " | Price: $" << price
                 << " | Quantity: " << quantity
                 << " | Expiry: " << expiry
                 << " | Country: " << country
                 << " | Generic: " << generic << "\n";
        }
    }

    if (!found) {
        cout << "No purchase history found for: " << search_name << "\n";
    }

    file.close();
    return 0;
}


int main() {
    cout << "     AURORA VIRTUAL PHARMACY  \n";
    cout << "             WELCOME          \n";

    string role;
    cout << "Enter your role (staff/customer): ";
    getline(cin, role);

    if (role == "staff") {
        int attempts = 3;  // Allow 3 attempts for password
        int entered_password;
        bool access_granted = false;

        while (attempts > 0) {
            cout << "Enter staff password: ";
            cin >> entered_password;
            cin.ignore();

            if (entered_password == passwordof_staff) {
                access_granted = true;
                break;
            } else {
                attempts--;
                cout << "Incorrect password. ";
                if (attempts > 0) {
                    cout << "Try again. (" << attempts << " attempts left)\n";
                } else {
                    cout << "No attempts left. Access denied.\n";
                }
            }
        }

        if (access_granted) {
            int choice;
            cout << "\nStaff Menu:\n";
            cout << "1. Update Stock\n";
            cout << "2. Search Medicine\n";
            cout << "3. See Daily Report\n";
            cout << "4. View Sales History\n";
            cout << "5. Exit to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                update_stock();
            } else if (choice == 2) {
                search_medicine();
            } else if (choice == 3) {
                daily_report();
            } else if (choice == 4) {
                view_history();
            } else if (choice == 5) {
                cout << "Returning to Main Menu.\n";
            } else {
                cout << "Invalid input!\n";
            }
        }
    } else if (role == "customer") {
        customer_service();
    } else {
        cout << "Invalid role. Please enter either 'staff' or 'customer'.\n";
    }

    return 0;
}

