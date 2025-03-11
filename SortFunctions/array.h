#include <iostream>
#include <iomanip>
using namespace std;

/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
//       fill
template <class T>
void fill(T ar[], int n)
{
  for (int i = 0; i < n ;i++)
  {
   cout << "Enter an item: ";
    cin >> ar[i];
}

}
//This function prints the array.


//ar is an array of any data type
//n is the number of items in ar
//********************************************
              // print
/*******************************************
//reading array elements from the user   
 // accessing array elements using the for loop  
 */
template <class T>
void print(T ar[], int n){
  for(int i = 0; i <n; i++ ){
   cout << ar[i] << " "  ;

  }

}  

//This function returns the index of the highest value.
//ar is an array of any data type.
//n is the number of items in ar

//*******************************************/
       //       getHighest
//ar is an array of any data type.
//n is the number of items in array
template <class T>
int getHigh(const T ar[], int n){
  int high = 0;
  for (int i= 1; i <n ;i++){
    if(ar[i] > ar[high]){
     high =i;
    }
  
  }
 return high;



}
//*******************************************/
       //       getLowest


template <class T>
  int getLow(const T ar[], int n){
  int low = 0;
  for (int i= 0; i <n ;i++){

     if ( ar[i] <ar[low] ){
          low = i;
         }
      }//end of forloop
    
  return low;
  }
 





/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
       //       getAvg
double getAvg(const int ar[],int n){
  int total =0;
  for (int i = 0; i < n; i++){
   total += ar[i];
  }

 return (double)total/n;
}


/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4
ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar and uniqAr
//uniqAr in the caller will be filled with only unique numbers
*******************************************/
template <class T>
int unique(const T ar[], T uniqAr[] , int n)
{
  int num;
  int counter =0;//count for # of unique nums in array
   // Pick all elements one by one
    for (int i=0; i<n; i++)
    {
      for(num = 0; num < i; num++){
          if (ar[i]== ar[num]){
           break;
          }
    

      }
      //comparing indexes
       if (i == num){
        uniqAr[counter] = ar[i];
        counter++; //access the first index
       }
    // Check if the picked element is already printed
     

    }
    return counter;
   

}

/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
  //last is the last index in unsorted portion                    //lrgIndx = 0; //assume the first item is the largest      //find the largest in unsorted portion ([0..last])         
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

template <class T>
void sort(T array[], int N)
{
int lrgIndx; //the index of the largest value
T temp; //temporary variable that holds the largest value
//last is the last index in unsorted area
for(int last = N-1; last >= 1; last--)
{
  
lrgIndx = 0; //assume the first item is the largest
//find the largest in unsorted area ([0..last])
for(int i = 1; i <= last; i++)
{
if(array[i] > array[lrgIndx]) //The current item is larger, then keep the current index
lrgIndx = i;
}
//swap the largest with the last item in the unsorted area
temp = array[lrgIndx];
array[lrgIndx] = array[last];
array[last] = temp;
}
}