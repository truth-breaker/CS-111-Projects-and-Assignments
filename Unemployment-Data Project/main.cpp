#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Unemployment{
  string website;
  double unemploymentRate;
  
};
/*
create a data file with a collection of real-world numeric data of your choice. Make sure to include the URL from which you have retrieved the data. 
*/
//https://ycharts.com/indicators/california_unemployment_rate
int main() {

  //Declare and initialize related variables and objects.
  Unemployment data;
  double lowest_droprate = .9999999;
  double highest_increase_rate = 0;
  int change;
  const unsigned MONTHS =12; 
  int month[MONTHS];//array that holds 12 months
  unsigned size =0; //size of array is 0 before intialization 
  //Read the data from your data file and store into an array variable.
  ifstream file;
  file.open("unemploymentRates.csv");
    if(!file.is_open()){
      cout << "File is not open properly.\n";
      return 1;
    }
    
    getline(file,data.website);
    cout << "\nThe following program analyzes the trend of 2020\n unemployment data for California.\n "; 
    cout << "REFERENCE: " << data.website << "\n";
    cout << left <<setw(19) << "Month" << setw(20) << "Rates" << setw(21) << "Change"<< endl;
    cout <<setfill('=')<< setw(55) << '=' <<endl;
    for(int i = 0; i < 12;i++){
    // i = i+1;
      month[i] = i+1;
    }
    int i =0;
    double rates[MONTHS];
    while(!file.eof()){
       //getline(file,data.website);
       file >> data.unemploymentRate;
       file.ignore();
       //getline(file,data.change,' ');
       //file >> data.change;
      
      rates[i]= data.unemploymentRate; 
      
      cout <<setfill(' ')<< left << setw(20) << month[i] << right<< setw(5) << data.unemploymentRate << "%"<< setw(20);
        if (month[i]== 1){
          cout <<setfill(' ') << "\t\t\tNo previous data available" << endl;
        }else{
        if(rates[i] > rates[i-1]){
           cout << right << "Up by " << rates[i]-rates[i-1]<< "%"<< endl;
           double high_increase = rates[i]-rates[i-1];
        if (highest_increase_rate < high_increase){
             highest_increase_rate = high_increase;
        }
        }else if ( rates[i] < rates[i-1]){
          cout <<right <<"Down by " << -1*(rates[i]-rates[i-1]) << "%" << endl;
          double lowrate= -1*(rates[i]-rates[i-1]);
        if (lowest_droprate > lowrate) {
             lowest_droprate = lowrate;
          }
        }
      }
      i++;
    };
     //rate[i]=number before
        
    
  
  
  
  /*Write a loop to iterate through the arrat elements and display a nicely formatted table showing how much the data has changed or remained the same from one element to the next
  */
    /*
  After the table, the program shall display both the largest increase and smallest drop from one element to another. 
  */
     
  cout << "\nIn the year 2020, from one month to the next,"; 
  cout << "the largest\n increase of unemployment rate was "<<  highest_increase_rate <<  "%";
  cout << " and the smallest drop was " << lowest_droprate << "%" << endl;
     


 
 


 
} 