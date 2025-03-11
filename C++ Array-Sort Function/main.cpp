#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
  
  int ai[] = {2,-6,18,17,29,-8,12,2};
  cout << "\n Sort from Least to Greatest" << endl;
  sort(ai,ai+8);
  
  for(int i=0; i<8; i++){
    
    cout << ai[i] << " ";
    
  }
  
  cout << " \n" << endl;
   
  cout << "Sort by Alphabetical Order" << endl;

  string as[] = {"abhla", "kals", "ha", "abhka", "iaoas", "kal"};
  
  sort(as, as+6);
  
  for(int j=0; j<6; j++){
    
    cout << as[j] << " ";
    
  }
  
  cout << " \n" << endl;
  
  
  vector<int> v;
  
  v.push_back(9);
  v.push_back(-1);
  v.push_back(17);
  v.push_back(19);
  v.push_back(0);
  v.push_back(-4);
  
  sort(v.begin(),v.end());
  
  vector<int>::iterator ib = v.begin();
  vector<int>::iterator ie = v.end();
  cout << "Sort from Least to Greatest (vector)" << endl;

  while(ib!=ie){
    
    cout << *ib << " ";
    ib++;
  }
  
  cout << endl;  
  
   
  
  return 0;
}