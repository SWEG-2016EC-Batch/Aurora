#include <iostream>
#include <string>
#include <cctype> // for tolower()
#include <algorithm>
using namespace std;  
int passwordof_staff=232425;
int passwordof_admin=131415;
string expireddate_checking(){
    
};
string customer_service(){
    cout<<"Thank you for choosing Aurora virtual pharmacy .our customer choose what kind of service you need?";
    cout<<"  0-";
    void upload_prescription();
}
string new_medicine(){

   string whole_seller
};
void generate_bill(){
    int tin_no;//TIN (Taxpayer Identification Number):
    //It’s a unique number assigned to a business or seller for tax purposes.
};
void update_stock(){

};
void search_medicine(){
string generic ;
string brand ;
 
};
void purchase_history(string customer_id){

};
void upload_prescription(){


};
string login(string role) {  
     
    int password;  

    cout << "Enter your password: ";  
    cin >> password;  
    if (role == "staff") {  
        if (password == passwordof_staff) {  
            return "";
        } else {  
            return "Invalid password";  
        }  
    } else if (role == "admin") {  
        if (password == passwordof_admin) {  
            return "";  
        } else {  
            return "Invalid password";    
        }  
    }  

    return "Invalid role";  
}  

void daily_sales_report(){

};
int main(){
cout<<"     AURORA VERTUAL PHARMACY  \n";
cout<<"             WELCOME   \n";
string role;  
    cout << "Enter your role (staff/admin/customer): ";  
    getline(cin, role);  

    if (role == "staff" || role == "admin") {  
          
        string result = login(role);  
        if (result.empty()) {  
            cout << "Login successful!\n";  
        } else {  
            cout << result << endl; 
        }  
    } else if (role == "customer") {  
        cout << customer_service();  
        generate_bill(); 
    } else {  
        cout << "Invalid input\n";    
    }  



    return 0;
}
