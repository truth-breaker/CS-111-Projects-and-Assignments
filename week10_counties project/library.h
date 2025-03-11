#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
//the struct definitions and function prototypes should be defined in the “library.h” file

/*
  Function Name: 	You get to choose a descriptive name.
  Return type: 		void
  Parameter: 	A County struct object.
  Function goal: 	The function is to display the data stored in the County object in a tabular format. 
*/ 
  struct County {
    string county_name;
    int covid_deaths;
    double vaccination_percentage;
  };

/*
  Function Name: 	You get to choose a descriptive name.
  Return type: 		void
  Parameter: 	A Stats struct object.
  Function goal: 	The function is to set the data members of the Stats object to appropriate initial values. 
*/ 
  struct Stats {
    double total_deaths;
    double total_fullyvaccinated;
    double highest_deaths;
    double lowest_deaths;
    string highest_county;
    string lowest_county;
    
    //unsigned tally;
   // unsigned average_deaths;
    
  };

/*
  Function Name: 	You get to choose a descriptive name.
  Return type: 		void
  Parameters: 	A Stats struct object and a County object.
  Function goal: 	The function is to update the data members of the Stats object according to the values of the data members in the County object.
*/ 

/*
  Function Name: 	You get to choose a descriptive name.
  Return type: 		void
  Parameter: 	A Stats struct object.
  Function goal: 	The function is to display the data stored in the Stats object in a nice, easy to understand manner. 
*/ 

void display_county(County& c);
void assign_initial(Stats& s);
void update_stats(Stats& s, County& c);
void display_stats(Stats& s);