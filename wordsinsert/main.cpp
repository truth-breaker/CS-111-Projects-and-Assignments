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
  cout << "What word would you like to insert?\t";
  cin >> str;


  /*
  cout << "What index should we add the new word?\t";
  cin >> pos;
  */

  int pos = 0;
  bool found = false;
  for (int i = num_words; i > 0 && !found; i--) {
    if (words[i - 1] > str ) {
      words[i] = words[i - 1];
    } else {
      found = true;
      pos = i;
    }
  } //end of search & shift
  words[pos] = str;
  num_words++;

  //for testing purpose:
  for (int i = 0; i < num_words; i++) {
    cout << words[i] << endl;
  }
}