#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1;
  //write your code here
  while(left<=right){
     int mid = left + (right-left)/2;
     //cout << "left: " << a[left] << " "<< "right: " << a[right] << " mid: " << a[mid] << endl;
     if(a[mid] == x) return mid;
     else if(a[mid] > x) right = mid-1;
     else left  = mid+1;
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

void test(const vector<int> test, const int& x){
   assert(linear_search(test, x) == binary_search(test, x));
   cout << "OK!" << endl;     
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
     cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
     cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //test(a, b[i]);
    //replace with the call to binary_search when implemented
    //cout << linear_search(a, b[i]) << ' ';
    cout << binary_search(a, b[i]) << ' ';
  }
}
