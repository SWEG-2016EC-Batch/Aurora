#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct Medicine {
    string brandName;
    string genericName;
    string country;
};
enum MenuOption {
    SEARCH_MEDICINE = 1,
    LOG_PURCHASE,
    VIEW_HISTORY,
    EXIT_PROGRAM
};
string toLower(const string& str) {
    string result = str;
    for (char& ch : result) {
        ch = tolower(ch);
    }
    return result;
}

void loadMedicines(vector<Medicine>& meds) {
    ifstream file("pharmacy.txt");
    if (!file) {
        cerr << "Sorry, pharmacy.txt file isn't found.\n";
        return;
    }

    Medicine m;
    while (file >> m.brandName >> m.genericName >> m.country) {
        meds.push_back(m);
    }
    file.close();
}


void searchMedicine(const vector<Medicine>& meds) {
    string keyword;
    cout << " Please enter brand or generic name to search: ";
    getline(cin, keyword);
    string searchKey = toLower(keyword);

    bool found = false;
    for (const auto& med : meds) {
        if (toLower(med.brandName) == searchKey || toLower(med.genericName) == searchKey) {
            cout << "\nCheers, We have this medicine:\n";
            cout << "Brand: " << med.brandName
                 << ", Generic: " << med.genericName
                 << ", Country: " << med.country << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Oh, Currently We don't have this medicine.\n";
}

void logPurchase() {
    string medName;
    int quantity;
    double unitPrice;

    cout << "Please enter medicine name: ";
    getline(cin, medName);

    cout << "Please enter quantity you want to purchase: ";
    cin >> quantity;
    cout << "Please enter unit price: ";
    cin >> unitPrice;
    cin.ignore();

    ofstream outFile("purchase_history.txt", ios::app);
    if (outFile) {
        outFile << toLower(medName) << " " << quantity << " " << unitPrice << endl;
        cout << "Congra, Purchase logged successfully.\n";
    } else {
        cout << "Error writing to history file.\n";
    }
    outFile.close();
}
void viewHistory() {
    ifstream inFile("purchase_history.txt");
    if (!inFile) {
        cerr << "Oh, No purchase history found.\n";
        return;
    }
    string medName;
    int qty;
    double price;

    cout << "\n--- Purchase History ---\n";
    while (inFile >> medName >> qty >> price) {
        cout << "Medicine: " << medName
             << ", Quantity: " << qty <<" Unit price "<<price
             << ", Total price: " << qty * price << endl;
    }
    inFile.close();
}

int main() {
    vector<Medicine> medicines;
    loadMedicines(medicines);

    int choice;
    do {
        cout << "\n *** Welcome to Aurora Pharmacy, You made the right choice ***\n";
        cout << "\n Aurora Pharmacy menu \n";
        cout << "1. Search Medicine\n";
        cout << "2. Log Purchase\n";
        cout << "3. View Purchase History\n";
        cout << "4. Exit\n";
        cout << "Please tell us the service you need: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case SEARCH_MEDICINE:
                searchMedicine(medicines);
                break;
            case LOG_PURCHASE:
                logPurchase();
                break;
            case VIEW_HISTORY:
                viewHistory();
                break;
            case EXIT_PROGRAM:
                cout << "*** BYE BYE, We miss you ***\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != EXIT_PROGRAM);

    return 0;
}
