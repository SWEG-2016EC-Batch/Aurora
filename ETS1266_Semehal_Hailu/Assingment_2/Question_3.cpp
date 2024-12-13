#include <iostream>
using namespace std;

int main() {
    int num, choice, temp, digit = 0, rev = 0, count = 0,prod = 1,first = 0, last = 0,sum=0,newNum = 0,freq = 0,strong = 0,perfect = 0;
    bool isPalindrome = true;

    cout << "Enter a number: ";
    cin >> num;
    temp = num;

    cout << "1. Reverse of the number" << endl;
    cout << "2. Number of digits" << endl;
    cout << "3. Product of even digits" << endl;
    cout << "4. First and last digit" << endl;
    cout << "5. Swap first and last digit" << endl;
    cout << "6. Palindrome" << endl;
    cout << "7. Frequency of first digit" << endl;
    cout << "8. Strong number" << endl;
    cout << "9. Perfect number" << endl;
    cout << "10. Exit" << endl;


    
    cout << "Enter your choice: ";
    cin >> choice;
    

    
    switch(choice) {
        case 1:
            while (temp > 0) {
                digit = temp % 10;
                rev = rev * 10 + digit;
                temp /= 10;
            }
            cout << "Reverse of the number: " << rev << endl;
            break;
        case 2:
             
            while (temp > 0) {
                count++;
                temp /= 10;
            }
            cout << "Number of digits: " << count << endl;

            break;
        case 3:
             
            while (temp > 0) {
                digit = temp % 10;
                if (digit % 2 == 0) {
                    prod *= digit;
                }
                temp /= 10;
            }
            cout << "Product of even digits: " << prod << endl;
            break;
        case 4:
             
            while (temp > 0) {
                digit = temp % 10;
                if (first == 0) {
                    first = digit;
                }
                last = digit;
                temp /= 10;
                sum= last + first;
            }
            cout << "First and last digit: " << first << " and " << last <<"and their sum"<<sum<< endl;
            
            break;
        case 5:
            while (temp > 0) {
                digit = temp % 10;
                if (digit == first) {
                    digit = last;
                } else if (digit == last) {
                    digit = first;
                }
                newNum = newNum * 10 + digit;
                temp /= 10;
            }
            cout << "Number after swapping: " << newNum << endl;
            break;
        case 6:
            while (temp > 0) {
                if (temp % 10 != rev % 10) {
                    isPalindrome = false;
                    break;
                }
                temp /= 10;
                rev /= 10;
            }
            if (isPalindrome) {
                cout << "Palindrome: Yes" << endl;
            } else {
                cout << "Palindrome: No" << endl;
            }
            break;
        case 7:
            while (temp > 0) {
                digit = temp % 10;
                if (digit == first) {
                    freq++;
                }
                temp /= 10;
            }
            cout << "Frequency of first digit: " << freq << endl;
            break;
        case 8:
            while (temp > 0) {
                digit = temp % 10;
                int fact = 1;
                for (int i = 1; i <= digit; i++) {
                    fact *= i;
                }
                strong += fact;
                temp /= 10;
            }
            if (strong == num) {
                cout << "Strong number: Yes" << endl;
            } else {
                cout << "Strong number: No" << endl;
            }
            break;
        case 9:
            for (int i = 1; i < num; i++) {
                if (num % i == 0) {
                    perfect += i;
                }
            }
            if (perfect == num) {
                cout << "Perfect number: Yes" << endl;
} else {
cout << "Perfect number: No" << endl;
            }
            break;
        case 10:
            cout << "Exiting..." << endl;
            break;
    }
    
     
    return 0;
}
