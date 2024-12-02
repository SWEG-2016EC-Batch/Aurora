/*A serial transmission line can transmit 960 characters a second. Write a program that will calculate how long it will take to send a file, given the file size.
  Test your program on a 400MB (419,430,400 byte) file which may take days.*/
#include<iostream>
using namespace std;

int main() {
    double size_in_MB;
    double time_in_seconds, time_in_hours, time_in_days;

    cout << "Please enter the size of the file you want to transmit in megabytes: " << endl;
    cin >> size_in_MB;

    double size_in_bytes = size_in_MB * 1048576; 
  // Convert MB to bytes
    time_in_seconds = size_in_bytes / 960;     
  // Calculate time in seconds
    time_in_hours = time_in_seconds / 3600;   
  // Convert time to hours
    time_in_days = time_in_hours / 24;         
  // Convert time to days

    cout << "The time it takes to transmit " << size_in_MB << " megabytes is: " << endl;
    cout << "Time in seconds = " << time_in_seconds << endl;
    cout << "Time in hours = " << time_in_hours << endl;
    cout << "Time in days = " << time_in_days << endl;

    return 0;
}

