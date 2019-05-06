#include <iostream>
#include <vector>
#include <algorithm>

void Print_vector(std::vector<int>& v){
   for(int& output:v) std::cout << output << " ";
   std::cout << std::endl;
}

int get_change(int m) {
  std::vector<int> arr(m+1);
  std::vector<int> coins(3);
  std::vector<int> values;
  //write your code here
  coins[0] = 1;
  coins[1] = 3;
  coins[2] = 4;
  arr[0] = 0;
  for(int i=1; i<arr.size(); i++){
     for(int j=0; j<coins.size(); j++ ){
        if(i >= coins[j]){
           values.push_back(arr[i - coins[j]] + 1);
        } 
     }
     std::sort(values.begin(), values.end());
     //Print_vector(values); 
     arr[i] = values[0];
     values.clear();     
     //std::cout << arr[i] << " ";
  }
  //std::cout << std::endl;
  return arr[arr.size()-1];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
