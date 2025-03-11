#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;
//prototypes
void fillArray (int ar[], int size);
bool findFunction(const int ar[],int size,int userskey);
void display(const int ar[],int size,int userskey);
void average(const int ar[], int size);
int main() {
  int key;
  srand(time(0));
  //declare a constant called SIZE & set it to 10
  const int SIZE = 10;
   //Declare int array that has SIZE slots
   int ar[SIZE];
   //call Fill array to fill the array with random numbers between 1-100
   fillArray(ar,SIZE);
   cout << "\nEnter the number you are looking for: ";
   cin >> key;
   //Call find function display "found" or "not found here"
   // findFunction(ar,SIZE,key);
  display(ar,SIZE,key);
  //Call Avg. Function
   average(ar,SIZE);
}
//function that generates the 10 random numbers 1-100
void fillArray (int ar[], int size){
for (int i = 0; i < size; i++) {
    ar[i] = rand() % 100+1;
    cout << right << setw(4);
   cout << ar[i] << " " ;

}
}
 bool findFunction(const int ar[],int size,int userskey){
   for (int i = 0;i < size ; i++){
   if(ar[i] == userskey) 
     return true;
  }
  return false;
}
void display(const int ar[],int size,int userskey){
  if(findFunction(ar,size,userskey)){
   cout << userskey << " was found in the array\n";
  }
  else{
    cout << userskey << " was not found in the array\n";
  }

}
void average(const int ar[], int size) {
  
  double sum = 0;
  for (int i = 0; i < size; i++){
    sum += ar[i];
  }
   double avg = sum/ size;
   cout << fixed << showpoint <<setprecision(2); 
   cout<<"The average numbers of the array "<< avg << endl;

}