#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int find_maj(vector<int>& arr){
   sort(arr.begin(), arr.end());
   int N = arr.size();
   if(N == 1) return 1;
   else if(N == 2) return -1;
   else{
     int i = 0;
     int count = 1;
     while(i <= N-2){
        std::cout << "Step " << i << std::endl;
        if(arr[i] == arr[i+1]){
           count++;
           i++;
           std::cout << "Equal! " << count << std::endl;
           if(count > N/2){
              //cout << "Found it! " << arr[i] << endl;
              return 1;
           }
        }
        else{
           i++;
           count = 1;
           continue;
        }
     }
   }
   return -1;
}

bool check_equal(const vector<int>& v, int left, int right){
   bool res = true;
   for(int i=left; i<(right - 1); i++) 
      if(v[i] != v[i+1]) res = false; 
   return res;
}

void print_arr(const vector<int>& v, const int& left, const int& right){
   for(int i=left; i<right; i++) std::cout << v[i] << " ";
   std::cout << std::endl;
}

int get_majority_element(vector<int> &a, int left, int right) {
  sort(a.begin(), a.end());
  std::cout << "Sorted array: " << std::endl;
  print_arr(a, left, right);
  if (left == right) return -1;
  //if (left + 1 == right) return a[left];
  //write your code here
  int mid = left + (right-left)/2;
  std::cout << "Mid: " << mid << std::endl;
  print_arr(a, left, mid); 
  print_arr(a, mid-1, a.size());
  if(check_equal(a, 0, mid+1)) return 1;
  else if(check_equal(a, mid-1, a.size())) return 1;
  return -1;
}

int get_majority_element_naive(vector<int> &a){
   for(int i=0; i<a.size(); i++){
      int count = 0;
      int cur_el = a[i];
      for(int j=0; j<a.size(); j++){
         if(a[j] == cur_el){
            count++;
         }
      }
      if(count > a.size()/2) {
        return 1;
      }
   }
   return -1;
}

int main() {
  
  //Stress test
  while(true){
     int n = rand()%4 + 7;
     std::cout << n << '\n';
     vector<int> a;
     for(int i = 0; i < n; i++) a.push_back(rand()%10);
     for(int n:a) std::cout << n << ' ';
     std::cout << std::endl;
     //int f = find_maj(a);
     int res_naive = get_majority_element_naive(a);
     int res_div_conquer = get_majority_element(a, 0, a.size());
     if(res_naive != res_div_conquer) {
         std::cout << "Wrong answer: " << res_naive << res_div_conquer << std::endl;
         break;
     }
     else std::cout << "OK" << std::endl;
    }
  
  //Now the main part
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
