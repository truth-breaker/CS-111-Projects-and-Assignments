#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
using namespace std;

// Structure to store city weather data
struct Forecast {
    string city;               // City name
    string state;              // State abbreviation
    int hourly_temps[24];      // Array storing 24-hour temperature data
};

// Function to display all forecast data
void display_all(const Forecast arr[], int n);

// Function to display the highest temperature for each city
void display_highs(const Forecast arr[], int n);

#endif // LIBRARY_H
