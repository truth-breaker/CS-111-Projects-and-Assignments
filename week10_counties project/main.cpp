#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "library.h"

using namespace std;

int main() {
   int tally = 0;
   double total_deaths = 0, total_vaccination_percentage = 0;  // Initialize totals
   vector<County> county_list;

    ifstream file;
    file.open("counties.csv");
    if(!file.is_open()){
        cout << "File is not open properly.\n";
        return 1;
    }

    cout << left << setw(19) << "COUNTY NAME"<<  setw(27) << "#of Covid-19 Deaths" << setw(16) << "Fully Vaccinated %" << endl;
    cout << "=========================================================\n";

    Stats stats_object;
    County county_object;
    assign_initial(stats_object);  // Initialize stats once

    while(getline(file, county_object.county_name, ',')){
        file >> county_object.covid_deaths;
        file.ignore();
        file >> county_object.vaccination_percentage;
        file.ignore();

        display_county(county_object);  // Display county data
        
        // Update the statistics
        update_stats(stats_object, county_object); 

        // Accumulate totals
        total_deaths += county_object.covid_deaths;
        total_vaccination_percentage += county_object.vaccination_percentage;

        tally++;
    }

    file.close();

    // After processing all counties, display summary statistics
    cout << "\nTotal deaths: " << total_deaths << endl;
    cout << "Total fully vaccinated: " << total_vaccination_percentage / tally << "%" << endl;

    display_stats(stats_object);  // Display stats after all counties are processed
}
