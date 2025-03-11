#include <iostream>
#include <iomanip>
using namespace std;
#include "array.h"
void test(int code);
void  fill(int ar[], int size);
void selectionSort1(int array[], int N);
void selectionSort2(int array[], int N);
void selectionSort3(int array[], int N);
void selectionSort4(int array[], int N);

int main()
{
  //to generate a different sequence of random numbers in every run. 
  srand(time(NULL)); 
  cout << "------ testing selectionSort1: Ascending moving largest to end  ------" << endl;
  test(1);

  cout << "\n------ testing selectionSort2: Descending moving smallest to end  ------"\
 << endl;
  test(2);

  cout << "\n------ testing selectionSort3: Ascending moving smallest to beginning  --\
----" << endl;
  test(3);
  cout << "\n------ testing selectionSort4: Descending moving largest to beginning  --\
----" << endl;
  test(4);
  cout << endl;
  return 0;
}

//This function fills the array with random numbers between 1 and 100
 void  fill(int ar[], int size)
{
  for (int i = 0; i < size ;i++)
  {    
    ar[i] = rand() % 100 + 1; //num gets some random number between 1 and 100
    cout << right << setw(4);
   //cout << ar[i] << " " ;
 }

}



//code = 1 for selectionSort1
//code   2 for selectionSort2
//code=  3 for selectionSort3
//code=  4 for selectionSort4

 void test(int code)
{
  //make a constant SIZE set to 10(Capacity of array =10)
   const int SIZE = 10;  
  //declare an integer array using SIZE// array hold 10 indexes-
  int ar[SIZE];
  //fill the array by calling fill()
   fill(ar,SIZE);
//print the array by calling print() in array.h
 
  print(ar,SIZE);
  cout << "\n";
  //create a switch statement here to call a different sort function depending on the \code.
  //swich cases allows to call the number of each function
  switch (code){
   case 1:
   selectionSort1(ar,SIZE);
  
   break;
   case 2:
  selectionSort2(ar,SIZE);

   break;
   case 3:
   selectionSort3(ar,SIZE);
   break;
   case 4:
   selectionSort4(ar,SIZE);
  } 
  
   
  //print the array - hopefully the numbers are sorted correctly
  print(ar,SIZE);
}



//this function sorts the numbers in ascending order by moving the largest to the end:\smallest to largest
void selectionSort1(int array[], int N)
{
  int lrgIndx; //the index of the largest value
  int temp; //temporary variable that holds the largest value

  //last is the last index in unsorted part
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted part ([0..last])
      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger
            lrgIndx = i;
        }

      //swap the largest with the last item in the unsorted part
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}
//Change this function so it sorts the numbers in descending order by moving the smallest to\the end: largest to smallest           

//You can change the variable names to suit their purposes.
//The structure of this code shouldn't change.
//Large to Small
void selectionSort2(int array[], int N)
{
  int smallIndx; //the index of the smallest  value                     
  int temp; //temporary variable that holds the smallest value
                                                                                          
  //for loop that makes sure each index/num is being checked from 10(last) to 1(first)                                                                       
  for(int last = N-1; last >= 1; last--)
    {
      smallIndx = 0; //assume the first item is smallest 
      //finds the smallest in unsorted part ([0..last])                                                              
      for(int i = 1; i <= last; i++)
        {
          if(array[i] < array[smallIndx]) //current item is smaller                   
          smallIndx = i;
        }

      //swap the smallest with the last item in the unsorted part 
     temp = array[smallIndx];
     array[smallIndx] = array[last];
      array[last] = temp;
    }
}

//Change this function so it sorts the numbers in ascending order by moving the smallest to the beginning: smallest to largest

//You can change the variable names to suit their purposes.                                                             
//The structure of this code shouldn't change.
void selectionSort3(int array[], int N)
{
  int smallIndx; //index of smallest value                          
  int temp; //temporary value to hold the smallest value           

  //search function                                               
  for(int first = N-1; first >= 0; first--)
    {
      smallIndx = 0; //assume the first item is smallest                                                                                
      //sort function starting at index 0                                                                                   
      for(int i = 0; i <= first; i++)
        {
          if(array[i] > array[smallIndx]) //current is small                                                                     
            smallIndx = i;
        }

      //swap the smallest with the beginnig item in the unsorted part                                         
      temp = array[smallIndx];
      array[smallIndx] = array[first];
      array[first] = temp;
    }
}

//Change this function so it sorts the numbers in descending order by moving the largest to the beginning: largest to smallest                              
//You can change the variable names to suit their purposes.  
//The structure of this code shouldn't change.

void selectionSort4(int array[], int N)
{
  int lrgIndx; //index of the largest value
  int temp; //temporary value to hold the smallest value 
  //beginning is the beginning index of the unsorted array                                                                       
  for(int beginning = N-1; beginning >= 1; beginning--)
    {
      lrgIndx = 0; //index start at 0                                             //sort function starting at index 0        
      //find the largest in the unsorted array
      for(int i = beginning ; i <= 1; i++)
        {
          if(array[i] < array[lrgIndx]) //current item is larger                                                   
            lrgIndx  = i;
        }
       //swap the largest with the beginning item in the unsorted part 
      temp = array[lrgIndx];
      array[lrgIndx] = array[beginning];
      array[beginning] = temp;
    }
}


