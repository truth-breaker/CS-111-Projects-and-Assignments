#include <iostream>
#include <string>
#include <fstream>
#include "library.h"
#include <vector>
#include <iomanip>

using namespace std;

// Function to display the data stored in the County object in a tabular format.
void display_county(County& c) {  // Pass by reference, not by value
    cout << left << setw(19) << c.county_name
         << right << setw(15) << c.covid_deaths
         << setw(16) << c.vaccination_percentage << "%" << endl;
}

// Function to set the data members of the Stats object to appropriate initial values.
void assign_initial(Stats& s) {
    s.total_deaths = 0;
    s.total_fullyvaccinated = 0;
    s.highest_deaths = -1;
    s.lowest_deaths = 1e6;
    s.highest_county = "";
    s.lowest_county = "";
}

// Function to update the data members of the Stats object based on County object data.
void update_stats(Stats& s, County& c) {
    // Update total deaths and vaccination percentages
    s.total_deaths += c.covid_deaths;
    s.total_fullyvaccinated += c.vaccination_percentage;

    // Check for highest and lowest deaths
    if (c.covid_deaths > s.highest_deaths) {
        s.highest_deaths = c.covid_deaths;
        s.highest_county = c.county_name;
    }
    if (c.covid_deaths < s.lowest_deaths || s.lowest_deaths == 0) {
        s.lowest_deaths = c.covid_deaths;
        s.lowest_county = c.county_name; 
    }
}
// Optional: Function to display the statistics stored in the Stats object.
void display_stats(Stats& s) {
    //cout << "Total deaths: " << s.total_deaths << endl;
    cout << "Total fully vaccinated: " << s.total_fullyvaccinated << "%" << endl;
    cout << "Highest deaths: " << s.highest_deaths << " in " << s.highest_county << endl;
    cout << "Lowest deaths: " << s.lowest_deaths << " in " << s.lowest_county << endl;
}

 

