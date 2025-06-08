#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;
int update_stock();
int search_medicine();
int daily_report();
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
time_t now = time(0);             // Get current time
    char* dt = ctime(&now);           // Convert to string format
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
            // Save to prescription file
            fout << name << "," << hospital_name << "," << age<<","<<dt << "," << medName << "," << price<< "," << quantity << "," << expiry << "," << country << "," << generic << "\n";
        }
    }

    cout << string(115, '=') << "\n";

    if (!found) {
        cout << " No medicines found with the generic name: " << genericSearch << "\n";
    }

    fout.close();
    file.close();
char buy; string location;
line:cout<<"Do you want to buy it if yes click Y unless click n \n";
cin>>buy;
if(buy=='Y'){
    cout<<"enter your adress with your phone please \n";
    cin>>location;
    cout<<"Your medicine arrive soon Thank you for choosing 5S Pharmacy\n";
}else if(buy=='n'){
    cout<<"It is cancelled Have a good day ";
}else{
    cout<<"invalid input \n";goto line;
}
    return 0;
}
int main() {
     cout << "     AURORA VIRTUAL PHARMACY  \n";
    cout << "             WELCOME          \n";

    string role;
    cout << "Enter your role (staff/customer): ";
    getline(cin, role);

    if (role == "staff") {
    int choice;
    cout << "\nStaff Menu:\n";
    cout << "1. Update Stock\n";
    cout << "2. Search Medicine\n";
    cout << "3. View Daily Sales Report\n";
    cout << "4. Exit to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // clear newline left in the input buffer

    if (choice == 1) {
        update_stock();
    }else if(choice == 2){
        search_medicine();
    }else if(choice== 3){
        daily_report();
    }}else if(role=="customer"){
        customer_service();
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
    cin.ignore(); // Clear buffer

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

            // Trim leading/trailing spaces
            expiry.erase(0, expiry.find_first_not_of(" \t"));
            expiry.erase(expiry.find_last_not_of(" \t") + 1);

            // Convert expiry to time struct
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
    getline(cin, medicine);  // To handle names with spaces

    ifstream files("pharmacy.txt");
    if (!files) {
        cout << " File not found! Make sure pharmacy.txt is in the correct folder.\n";
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

    while (getline(files, line)) {
        stringstream ss(line);
        string medName, price, quantity, expiry, country, generic;

        getline(ss, medName, '|');
        getline(ss, price, '|');
        getline(ss, quantity, '|');
        getline(ss, expiry, '|');
        getline(ss, country, '|');
        getline(ss, generic, '|');

        // Trim extra spaces
        medName.erase(0, medName.find_first_not_of(" \t"));
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

    files.close();
    return 0;
}
int daily_report() {
    ifstream file("prescription.txt");
    string line1, line2, input_date;

    if (!file.is_open()) {
        cerr << "Error: Could not open prescription.txt\n";
        return 1;
    }

    cout << "Enter the date (e.g., Sun Jun 08 02:02:22 2025): ";
    getline(cin, input_date);

    cout << "\n--- Daily Report for " << input_date << " ---\n";
    bool found = false;

    while (getline(file, line1) && getline(file, line2)) {
        stringstream ss1(line1);
        stringstream ss2(line2);

        string field1, field2;
        string patient[3], med[6];

        // Extract first line fields
        int i = 0;
        while (getline(ss1, field1, ',') && i < 3) {
            patient[i++] = field1;
        }

        // Extract second line fields
        i = 0;
        while (getline(ss2, field2, ',') && i < 6) {
            med[i++] = field2;
        }

        // Extract date from patient[2], remove leading number if necessary
        string full_date = patient[2].substr(patient[2].find_first_not_of("0123456789"));

        if (full_date == input_date) {
            found = true;
            cout << "Patient: " << patient[0] << " " << patient[1] << endl;
            cout << "Medicine: " << med[0] << endl;
            cout << "Price: $" << med[1] << endl;
            cout << "Quantity: " << med[2] << endl;
            cout << "Expiry: " << med[3] << endl;
            cout << "Country: " << med[4] << endl;
            cout << "Generic Name: " << med[5] << endl;
            cout << "-----------------------------\n";
        }
    }

    if (!found) {
        cout << "No records found for this date.\n";
    }

    file.close();
    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int view_history() {
    ifstream file("prescription.txt");
    string line1, line2;
    string input_name;

    if (!file.is_open()) {
        cerr << "Error: Could not open prescription.txt\n";
        return 1;
    }

    cout << "Enter the patient's name to view history: ";
    getline(cin, input_name);

    // Convert input to lowercase for case-insensitive matching
    transform(input_name.begin(), input_name.end(), input_name.begin(), ::tolower);

    cout << "\n--- Purchase History for \"" << input_name << "\" ---\n";
    bool found = false;

    while (getline(file, line1) && getline(file, line2)) {
        stringstream ss1(line1);
        stringstream ss2(line2);

        string patient[3], med[6];
        string temp;
        int i = 0;

        // Parse line1: Patient data
        while (getline(ss1, temp, ',') && i < 3) {
            patient[i++] = temp;
        }

        // If name is empty, skip
        if (patient[0].empty()) continue;

        // Normalize for case-insensitive comparison
        string full_name = patient[0] + " " + patient[1];
        transform(full_name.begin(), full_name.end(), full_name.begin(), ::tolower);

        // Match input name
        if (full_name.find(input_name) != string::npos) {
            found = true;

            // Parse line2: Medicine data
            i = 0;
            while (getline(ss2, temp, ',') && i < 6) {
                med[i++] = temp;
            }

            // Extract date from patient[2]
            string date_info = patient[2];
            size_t pos = date_info.find_first_not_of("0123456789");
            string full_date = (pos != string::npos) ? date_info.substr(pos) : "Unknown";

            // Display record
            cout << "Date: " << full_date << endl;
            cout << "Medicine: " << med[0] << endl;
            cout << "Price: $" << med[1] << endl;
            cout << "Quantity: " << med[2] << endl;
            cout << "Expiry: " << med[3] << endl;
            cout << "Country: " << med[4] << endl;
            cout << "Generic Name: " << med[5] << endl;
            cout << "-----------------------------\n";
        }
    }

    if (!found) {
        cout << "No purchase records found for that name.\n";
    }

    file.close();
    return 0;
}

