#include <iostream>    // For input/output streams
#include <fstream>     // For file operations
#include <string>      // For using std::string
#include <cctype>      // For character handling (like tolower)
#include <algorithm>   // For std::transform
#include <iterator>    // For iterators (not used explicitly here)
#include <set>         // For std::set (not used explicitly here)
#include <sstream>     // For stringstream to parse strings
#include <cstdlib>     // For system(), srand(), rand()
#include <ctime>       // For time() used in seeding random number generator
#include <iomanip>     // For formatted output like setw, setprecision
#include <vector>
using namespace std;

// Function declarations for various pharmacy operations
void generate_bill();
void update_stock();
void search_medicine();
void daily_sales_report();
string new_medicine();                // Placeholder function, currently unused
void purchase_history(string customer_id);
string login(string role);
void staff_menu();

int passwordof_staff = 232425;      // Staff password hardcoded for login

// Placeholder function (unused in your current code)
string expireddate_checking() {
    return "";
}

// Handles customer interaction: Extract prescription text, display it and search medicines
int customer_service() {
    cout << "Thank you for choosing Aurora Virtual Pharmacy.\n";

    string imagePath;
    cout << "Please enter the path to your prescription image (e.g., prescription.jpg): ";
    getline(cin, imagePath);

    ofstream fout("prescription.txt", ios::app);
    if (!fout) {
        cout << "❌ Failed to open prescription.txt\n";
        return 1;
    }
    fout << imagePath << endl;
    fout.close();
ifstream file("pharmacy.txt");
    if (!file) {
        cout << "❌ File not found! Make sure pharmacy.txt is in the correct folder." << endl;
        return 1;
    }
    // Ask user for generic name to search
    string genericName;
    cout << "searching.........................................";
    while (getline(cin, genericName)){
        if(imagePath==genericName){
    cout << "\nSearching for medicines with generic name: " << genericName << endl;
    cout << "Medicine Name      | Price ($) | Quantity | Expiry Date | Country of Origin | Generic Name\n";
    cout << "----------------------------------------------------------------------------------------------\n";
 }
    }
    file.close();

  
    return 0;
}


// Generates and displays a formatted bill from prescription.txt file
void generate_bill() {
    ifstream file("prescription.txt");
    if (!file) {
        cout << "❌ Cannot open prescription.txt. Make sure it exists.\n";
        return;
    }

    // Variables to store extracted patient and medicine info
    string line, name = "Unknown", age = "Unknown", medicine = "Unknown", generic = "Unknown", med_name = "Unknown";

    // Read file line by line and extract relevant info based on keywords
    while (getline(file, line)) {
        string lower_line = line;
        transform(lower_line.begin(), lower_line.end(), lower_line.begin(), ::tolower); // Convert line to lowercase for case-insensitive search

        if (lower_line.find("name") != string::npos) {
            name = line.substr(line.find(":") + 1);
            name.erase(0, name.find_first_not_of(" \t"));  // Trim leading whitespace
        } else if (lower_line.find("age") != string::npos) {
            age = line.substr(line.find(":") + 1);
            age.erase(0, age.find_first_not_of(" \t"));
        } else if (lower_line.find("medicine") != string::npos && lower_line.find("generic") == string::npos) {
            medicine = line.substr(line.find(":") + 1);
            medicine.erase(0, medicine.find_first_not_of(" \t"));
            med_name = medicine; // Assuming the medicine name is same as mentioned
        } else if (lower_line.find("generic") != string::npos) {
            generic = line.substr(line.find(":") + 1);
            generic.erase(0, generic.find_first_not_of(" \t"));
        }
    }
    file.close();

    // Generate a random 3-digit TIN number for the bill
    srand(time(0));
    int tin_no = 100 + rand() % 900;

    // Print the formatted bill
    cout << "\n----------------------------------------\n";
    cout << "         - AURORA PHARMACY -\n";
    cout << "Name           : " << name << endl;
    cout << "Age            : " << age << endl;
    cout << "Medicine       : " << medicine << endl;
    cout << "TIN Number     : " << tin_no << endl;
    cout << "Generic Name   : " << generic << endl;
    cout << "Medicine Name  : " << med_name << endl;
    cout << "----------------------------------------\n";
}

// Allows staff to update stock or add new medicines to the pharmacy.txt file
void update_stock() {
    // Read current stock lines into vector
    ifstream file("pharmacy.txt");
    vector<string> stock_lines;
    string line;

    while (getline(file, line)) {
        stock_lines.push_back(line);
    }
    file.close();

    // Take input for new medicine or stock update
    string medName, price, quantity, expiry, country, generic;
    cout << "Enter medicine brand name: ";
    getline(cin, medName);
    cout << "Enter price: ";
    getline(cin, price);
    cout << "Enter quantity to add: ";
    getline(cin, quantity);
    cout << "Enter expiry date (YYYY-MM-DD): ";
    getline(cin, expiry);
    cout << "Enter country of origin: ";
    getline(cin, country);
    cout << "Enter generic name: ";
    getline(cin, generic);

    bool updated = false;
    for (int i = 0; i < (int)stock_lines.size(); i++) {
        stringstream ss(stock_lines[i]);
        string existingMedName;
        ss >> existingMedName;

        // Check if medicine already exists in stock
        if (existingMedName == medName) {
            string oldPrice, oldQuantity, oldExpiry, oldCountry, oldGeneric;
            ss >> oldPrice >> oldQuantity >> oldExpiry >> oldCountry >> oldGeneric;

            // Add new quantity to old quantity
            int oldQtyInt = stoi(oldQuantity);
            int addQtyInt = stoi(quantity);
            int newQty = oldQtyInt + addQtyInt;

            // Update the line with new quantity and possibly other details
            stock_lines[i] = medName + " " + price + " " + to_string(newQty) + " " + expiry + " " + country + " " + generic;
            updated = true;
            break;
        }
    }

    // If medicine does not exist, add as new entry
    if (!updated) {
        stock_lines.push_back(medName + " " + price + " " + quantity + " " + expiry + " " + country + " " + generic);
    }

    // Write back updated stock to the file
    ofstream outfile("pharmacy.txt");
    for (const auto& s : stock_lines) {
        outfile << s << endl;
    }
    outfile.close();

    cout << (updated ? "Stock updated successfully.\n" : "New medicine added to stock.\n");
}

// Allows staff to search for medicines by generic or brand name in pharmacy.txt
void search_medicine() {
    ifstream file("pharmacy.txt");
    if (!file) {
        cout << "❌ Cannot open pharmacy.txt. Make sure it exists.\n";
        return;
    }

    int option;
    string keyword;
    cout << "Search by:\n";
    cout << "1. Generic Name\n";
    cout << "2. Brand Name (Medicine Name)\n";
    cout << "Enter choice: ";
    cin >> option;
    cin.ignore(); // Clear newline after integer input

    cout << "Enter name to search: ";
    getline(cin, keyword);
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower); // convert search keyword to lowercase for case-insensitive search

    string line;
    bool found = false;
    cout << "\n🔍 Search Results:\n";
    cout << "Medicine Name      | Price ($) | Quantity | Expiry Date | Country of Origin | Generic Name\n";
    cout << "----------------------------------------------------------------------------------------------\n";

    // Read through pharmacy.txt line by line and match with keyword
    while (getline(file, line)) {
        stringstream ss(line);
        string medName, price, quantity, expiry, country, generic;
        ss >> medName >> price >> quantity >> expiry >> country >> generic;

        string med_lower = medName;
        string generic_lower = generic;
        transform(med_lower.begin(), med_lower.end(), med_lower.begin(), ::tolower);
        transform(generic_lower.begin(), generic_lower.end(), generic_lower.begin(), ::tolower);

        // Check based on search option
        if ((option == 1 && generic_lower.find(keyword) != string::npos) ||
            (option == 2 && med_lower.find(keyword) != string::npos)) {
            found = true;
            cout << medName << "\t\t" << price << "\t   " << quantity << "\t   " << expiry << "\t   " << country << "\t\t" << generic << endl;
        }
    }

    if (!found) {
        cout << "❌ No medicine found matching \"" << keyword << "\"\n";
    }

    file.close();
}

// Displays the daily sales report by reading sales.txt
void daily_sales_report() {
    ifstream salesFile("sales.txt");
    if (!salesFile) {
        cout << "❌ sales.txt file not found.\n";
        return;
    }

    string date;
    string medicine;
    int quantity;
    double totalPrice;

    int totalItemsSold = 0;
    double totalRevenue = 0.0;

    cout << "\n📅 Daily Sales Report\n";
    cout << left << setw(15) << "Date" 
         << setw(20) << "Medicine" 
         << setw(10) << "Quantity" 
         << setw(12) << "Total Price ($)" << endl;
    cout << "------------------------------------------------------------\n";

    // Read sales file line by line to summarize data
    while (salesFile >> date >> medicine >> quantity >> totalPrice) {
        cout << setw(15) << date 
             << setw(20) << medicine 
             << setw(10) << quantity 
             << setw(12) << fixed << setprecision(2) << totalPrice << endl;

        totalItemsSold += quantity;
        totalRevenue += totalPrice;
    }

    cout << "------------------------------------------------------------\n";
    cout << "Total Items Sold: " << totalItemsSold << endl;
    cout << "Total Revenue   : $" << fixed << setprecision(2) << totalRevenue << endl;

    salesFile.close();
}

// Displays purchase history for a particular customer from purchase_history.txt
void purchase_history(string customer_id) {
    ifstream purchaseFile("purchase_history.txt");
    if (!purchaseFile) {
        cout << "❌ purchase_history.txt file not found.\n";
        return;
    }

    string custID, date, medicine;
    int quantity;
    double totalPrice;

    bool found = false;

    cout << "\n📜 Purchase History for Customer ID: " << customer_id << "\n";
    cout << left << setw(15) << "Date" 
         << setw(20) << "Medicine" 
         << setw(10) << "Quantity" 
         << setw(12) << "Total Price ($)" << endl;
    cout << "------------------------------------------------------------\n";

    // Read purchase file and display only records matching customer_id
    while (purchaseFile >> custID >> date >> medicine >> quantity >> totalPrice) {
        if (custID == customer_id) {
            found = true;
            cout << setw(15) << date 
                 << setw(20) << medicine 
                 << setw(10) << quantity 
                 << setw(12) << fixed << setprecision(2) << totalPrice << endl;
        }
    }

    if (!found) {
        cout << "No purchase records found for Customer ID: " << customer_id << "\n";
    }

    purchaseFile.close();
}

// Placeholder function (currently unused)
string new_medicine() {
    string whole_seller;
    return whole_seller;
}

// Handles staff login by checking entered password
string login(string role) {
    int password;
    cout << "Enter your password: ";
    cin >> password;

    if (role == "staff") {
        if (password == passwordof_staff) {
            return ""; // Empty string means success
        } else {
            return "Invalid password"; // Return error message on failure
        }
    }
    return "Invalid role"; // If role is not staff, reject login
}

// Staff menu for actions with continuous choice input until exit
void staff_menu() {
    int choice;
    do {
        cout << "\n🛠️ Staff Menu:\n";
        cout << "1. Generate Bill\n";
        cout << "2. Update Stock\n";
        cout << "3. Search Medicine\n";
        cout << "4. View Daily Sales Report\n";
        cout << "5. Exit to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                generate_bill();
                break;
            case 2:
                update_stock();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                daily_sales_report();
                break;
            case 5:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    cout << "     AURORA VIRTUAL PHARMACY  \n";
    cout << "             WELCOME          \n";

    string role;
    cout << "Enter your role (staff/customer): ";
    getline(cin, role);

    if (role == "staff") {
        int choice;
            do {
                cout << "\n🛠️ Staff Menu:\n";
                cout << "1. Generate Bill\n";
                cout << "2. Update Stock\n";
                cout << "3. Search Medicine\n";
                cout << "4. View Daily Sales Report\n";
                cout << "5. View Purchase History\n";
                cout << "6. Exit to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore(); // clear newline from input buffer

                switch (choice) {
                    case 1:
                        generate_bill();
                        break;
                    case 2:
                        update_stock();
                        break;
                    case 3:
                        search_medicine();
                        break;
                    case 4:
                        daily_sales_report();
                        break;
                    case 5: {
                        string custID;
                        cout << "Enter Customer ID to view purchase history: ";
                        getline(cin, custID);
                        purchase_history(custID);
                        break;
                    }
                    case 6:
                        cout << "Returning to main menu...\n";
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                }
            } while (choice != 6);

        } 
    else if(role=="customer") {
        customer_service();
    }
    else{
        cout << "Invalid input\n";
    }

    return 0;
}
