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
int generate_billing();

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
    cout << "Enter the date (e.g., Sun Jun 08 02:48:13 2025): ";
    getline(cin, input_date);

    string line;
    bool found = false;

    cout << "\n" << string(140, '=') << "\n";
    cout << "| " << left << setw(15) << "Customer Name"
         << "| " << setw(15) << "Hospital Name"
         << "| " << setw(5) << "Age"
         << "| " << setw(30) << "Purchase Date"
         << "| " << setw(18) << "Medicine Name"
         << "| " << setw(8) << "Price"
         << "| " << setw(8) << "Quantity"
         << "| " << setw(15) << "Expiry"
         << "| " << setw(15) << "Country"
         << "| " << setw(25) << "Generic Name" << "|\n";
    cout << string(140, '-') << "\n";

    while (getline(file, line)) {
        stringstream ss(line);
        string customer_name, hospital_name, age, purchase_date, medName, price, quantity, expiry, country, generic;

        getline(ss, customer_name, ',');
        getline(ss, hospital_name, ',');
        getline(ss, age, ',');
        getline(ss, purchase_date, ',');
        getline(ss, medName, ',');
        getline(ss, price, ',');
        getline(ss, quantity, ',');
        getline(ss, expiry, ',');
        getline(ss, country, ',');
        getline(ss, generic, ',');

        if (purchase_date == input_date) {
            cout << "| " << left << setw(15) << customer_name
                 << "| " << setw(15) << hospital_name
                 << "| " << setw(5) << age
                 << "| " << setw(30) << purchase_date
                 << "| " << setw(18) << medName
                 << "| " << setw(8) << price
                 << "| " << setw(8) << quantity
                 << "| " << setw(15) << expiry
                 << "| " << setw(15) << country
                 << "| " << setw(25) << generic << "|\n";
            found = true;
        }
    }

    cout << string(140, '=') << "\n";

    if (!found) {
        cout << "No purchases found on the date: " << input_date << "\n";
    }

    file.close();
    return 0;
}
int generate_billing() {
    ifstream fin("prescription.txt");
    if (!fin.is_open()) {
        cerr << "❌ Error: Could not open prescription.txt\n";
        return 1;
    }

    string target_name;
    cout << "Enter the customer's name to generate bill: ";
    getline(cin, target_name);

    string line1, line2;
    bool found = false;
    double total = 0.0;

    cout << "\n --- BILL RECEIPT ---\n";
    cout << string(60, '=') << "\n";
    cout << left << setw(20) << "Medicine"
         << setw(10) << "Price"
         << setw(10) << "Qty"
         << setw(15) << "Total" << "\n";
    cout << string(60, '-') << "\n";

    while (getline(fin, line1) && getline(fin, line2)) {
        stringstream ss1(line1), ss2(line2);
        string name, hospital, age, date;
        string blank, medName, priceStr, qtyStr, expiry, country, generic;

        getline(ss1, name, ',');
        getline(ss1, hospital, ',');
        getline(ss1, age, ',');
        getline(ss1, date); // rest of line1 is the date string

        getline(ss2, blank, ','); // empty field
        getline(ss2, medName, ',');
        getline(ss2, priceStr, ',');
        getline(ss2, qtyStr, ',');
        getline(ss2, expiry, ',');
        getline(ss2, country, ',');
        getline(ss2, generic);

        if (name == target_name) {
            double price = stod(priceStr);
            int qty = stoi(qtyStr);
            double lineTotal = price * qty;
            total += lineTotal;

            cout << left << setw(20) << medName
                 << setw(10) << fixed << setprecision(2) << price
                 << setw(10) << qty
                 << setw(15) << lineTotal << "\n";
            found = true;
        }
    }

    if (found) {
        cout << string(60, '-') << "\n";
        cout << right << setw(40) << "Grand Total: " << setw(10) << fixed << setprecision(2) << total << "\n";
        cout << string(60, '=') << "\n";
        cout << "🧾 Thank you for choosing 5S Virtual Pharmacy!\n";
    } else {
        cout << "⚠️ No records found for customer: " << target_name << "\n";
    }

    fin.close();
    return 0;
}

int view_history() {
    string search_name;
    cout << "Enter your name: ";
    getline(cin, search_name);

    ifstream file("prescription.txt");
    if (!file) {
        cout << "File not found!\n";
        return 1;
    }

    bool found = false;
    string line;

    cout << "\n" << string(140, '=') << "\n";
    cout << "| " << left << setw(15) << "Customer Name"
         << "| " << setw(15) << "Hospital Name"
         << "| " << setw(5) << "Age"
         << "| " << setw(30) << "Purchase Date"
         << "| " << setw(18) << "Medicine Name"
         << "| " << setw(8) << "Price"
         << "| " << setw(8) << "Quantity"
         << "| " << setw(15) << "Expiry"
         << "| " << setw(15) << "Country"
         << "| " << setw(25) << "Generic Name" << "|\n";
    cout << string(140, '-') << "\n";

    while (getline(file, line)) {
        stringstream ss(line);
        string customer_name, hospital_name, age, purchase_date, medName, price, quantity, expiry, country, generic;

        getline(ss, customer_name, ',');
        getline(ss, hospital_name, ',');
        getline(ss, age, ',');
        getline(ss, purchase_date, ',');
        getline(ss, medName, ',');
        getline(ss, price, ',');
        getline(ss, quantity, ',');
        getline(ss, expiry, ',');
        getline(ss, country, ',');
        getline(ss, generic, ',');

        // case-insensitive search
        string lower_customer_name = customer_name;
        string lower_search_name = search_name;
        transform(lower_customer_name.begin(), lower_customer_name.end(), lower_customer_name.begin(), ::tolower);
        transform(lower_search_name.begin(), lower_search_name.end(), lower_search_name.begin(), ::tolower);

        if (lower_customer_name == lower_search_name) {
            cout << "| " << left << setw(15) << customer_name
                 << "| " << setw(15) << hospital_name
                 << "| " << setw(5) << age
                 << "| " << setw(30) << purchase_date
                 << "| " << setw(18) << medName
                 << "| " << setw(8) << price
                 << "| " << setw(8) << quantity
                 << "| " << setw(15) << expiry
                 << "| " << setw(15) << country
                 << "| " << setw(25) << generic << "|\n";
            found = true;
        }
    }

    cout << string(140, '=') << "\n";

    if (!found) {
        cout << "No history found for customer: " << search_name << "\n";
    }

    file.close();
    return 0;
}




int main() {
    int choice;
    while (true) {
        cout << "\n==== 5S Virtual Pharmacy System ====\n";
        cout << "1. Customer Service\n";
        cout << "2. Update Stock (Staff Only)\n";
        cout << "3. Search Medicine\n";
        cout << "4. Daily Report\n";
        cout << "5. View Purchase History\n";
        cout << "6. Generate Billing\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // consume newline

        switch (choice) {
            case 1:
                customer_service();
                break;
            case 2: {
                int pw;
                cout << "Enter staff password: ";
                cin >> pw;
                cin.ignore();
                if (pw == passwordof_staff) {
                    update_stock();
                } else {
                    cout << "Invalid password!\n";
                }
                break;
            }
            case 3:
                search_medicine();
                break;
            case 4:
                daily_report();
                break;
            case 5:
                view_history();
                break;
            case 6:
                generate_billing();
                break;
            case 7:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter a number 1-7.\n";
        }
    }
    return 0;
}
