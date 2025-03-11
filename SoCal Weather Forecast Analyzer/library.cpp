#include <iostream>
#include <iomanip>
#include <string>
#include "library.h"
using namespace std;

// Display all forecast data
void display_all(const Forecast arr[], int n) {
    for (int i_city = 0; i_city < n; i_city++) {
        cout << "City: " << arr[i_city].city << ", State: " << arr[i_city].state << endl;
        cout << "Hourly Temperatures: ";
        
        for (int i_hour = 0; i_hour < 24; i_hour++) {
            cout << setw(2) << arr[i_city].hourly_temps[i_hour] << " ";
        }
        
        cout << "\n-------------------------------\n";
    }
}

// Display the highest temperature for each city
void display_highs(const Forecast arr[], int n) {
    cout << left << setw(15) << "City" 
         << setw(12) << "State" 
         << setw(10) << "High Temp" << endl;
    cout << "--------------------------------------" << endl;

    for (int i_city = 0; i_city < n; i_city++) {
        int highest = arr[i_city].hourly_temps[0];

        // Find the highest temperature of the day
        for (int i_hour = 1; i_hour < 24; i_hour++) {
            if (highest < arr[i_city].hourly_temps[i_hour]) {
                highest = arr[i_city].hourly_temps[i_hour];
            }
        }

        // Print the highest temperature
        cout << left << setw(15) << arr[i_city].city
             << setw(12) << arr[i_city].state
             << setw(10) << highest << endl;
    }
}
