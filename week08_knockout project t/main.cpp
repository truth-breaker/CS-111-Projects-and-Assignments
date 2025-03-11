#include <iostream>
#include <string>
using namespace std;
struct Dice{
unsigned first, second;
};
void roll(Dice&d);
void score_update(Dice&d);

int main() {
  cout << "Welcome to the Knock-out game" << endl; 
srand(time(NULL));  //to plant the seed for the random number generator
Dice dice;
  //char yes_no_response = 'Y';
  
  unsigned pairs = 0;
  int number_rounds;
  
  cout << "How many rounds of rolling would you like to have ? ";
  cin >> number_rounds;
  
  int r = 1; 
  //cout << " Round #" << r << ":" << endl ; 
  do{
      roll(dice); 
    cout << " Round #" << r << ":" << endl ; 

     r++;
   cout << " Dice rolled: "<<dice.first<< ", "<< dice.second << "\n";
   
   
  score_update(dice);
 
       
        
       
} while (r <= number_rounds);

}
void roll(Dice&d) {
 d.first = rand() % 6 + 1;
  d.second = rand() % 6 + 1;
 }

 void score_update(Dice&d)
 {
 int current_score  = d.first + d.second;
  if (current_score != 7){
     cout << "Current Score: " << current_score << "\n\n";      
     }
     else{
      current_score = 0; 
     cout << "Current Score:" << current_score << endl; 
     }
      
       

 }
 
 