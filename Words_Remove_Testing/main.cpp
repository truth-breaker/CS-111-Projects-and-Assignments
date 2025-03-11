#include <iostream>
#include <string>
using namespace std;

int main() {
  //Declare and initialize the words array and its companion variable
  const int SIZE = 10;
  string words[SIZE] = {"a", "act", "at", "cat", "tac"};
  int num_words = 5;

  //Declare and collect the word to be removed
  string str;
  cout << "What word would you like to remove?\t";
  cin >> str;

  //Look for the index of the matching element
  int pos = num_words;    //This is to ensure pos is not a valid index
  bool found = false; 
  for (int i = 0; i < num_words && !found; i++) {
    if (str == words[i]) {
      found = true;
      pos = i;
    }
  } //end of search for the index of str

  if (found) {
    //remove by position
    for (int i = pos; i< num_words - 1; i++) {
      words[i] = words[i + 1];
    }
    num_words--;
  } else {
    cout << str << " is not in the array." << endl;
  }

  //for testing purpose:
  for (int i = 0; i < num_words; i++) {
    cout << words[i] << endl;
  }
}