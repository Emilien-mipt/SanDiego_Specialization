#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool find_maj(vector<int>& arr){
   sort(arr.begin(), arr.end());
   int N = arr.size();
   if(N == 1) return 1;
   else if(N == 2) return -1;
   else{
     int i = 0;
     int count = 1;
     while(i <= N-2){
        //std::cout << "Step " << i << std::endl;
        if(arr[i] == arr[i+1]){
           count++;
           i++;
           //std::cout << "Equal! " << count << std::endl;
           if(count > N/2){
              //cout << "Found it! " << arr[i] << endl;
              return true;
           }
        }
        else{
           i++;
           count = 1;
           continue;
        }
     }
   }
   return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
     cin >> a[i];
  }
  cout << find_maj(a) << '\n';
  return 0;
}
