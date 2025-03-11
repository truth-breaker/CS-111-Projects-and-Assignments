#include <iostream>
#include <fstream>
#include <iomanip>
#include "library.h"

using namespace std;

int main() {
    Forecast southern_ca[20];  // Array for up to 20 cities
    int num_cities = 3;  // Adjust based on actual data

    ifstream input("data.txt");
    if (!input.is_open()) {
        cout << "Can't open data.txt.\n";
        return 1;
    }

    cout << left << setw(15) << "City" 
         << setw(12) << "State" 
         << setw(10) << "High Temp" << endl;
    cout << "--------------------------------------" << endl;

    for (int i_city = 0; i_city < num_cities; i_city++) {
        // Read city and state
        getline(input, southern_ca[i_city].city, ',');
        getline(input >> ws, southern_ca[i_city].state);  // Trim leading spaces

        // Read hourly temperatures
        for (int i_hour = 0; i_hour < 24; i_hour++) {
            if (!(input >> southern_ca[i_city].hourly_temps[i_hour])) {
                cerr << "Error reading temperatures!\n";
                return 1;
            }
        }

        input.ignore(); 
    }

    // Display all city data
    display_all(southern_ca, num_cities);

    // Display high temperatures
    display_highs(southern_ca, num_cities);

    input.close();
    return 0;
}
