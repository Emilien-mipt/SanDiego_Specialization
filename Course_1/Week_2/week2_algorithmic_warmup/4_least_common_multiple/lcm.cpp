#include <iostream>
#include <cassert>
#include <cmath>

//We will use the fact that lcm(a, b) = abs(a*b)/gcd(a,b)

long long gcd(long long a, long long b) {
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}
    
long long lcm_fast(long long a, long long b){
    return (a*b)/gcd(a, b);
}




long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_naive_2(long long a, long long b) {
    long long max = (a>b) ? a:b;
    while(true){
        if((max % a == 0) && (max % b == 0)) break;
        ++max;
    }
    return max;
}

int test(){
    assert(lcm_fast(6, 8) == 24);
    assert(lcm_fast(28851538, 1183019) == 1933053046);
    assert(lcm_fast(14159572, 63967072) == 226436590403296);
    assert(lcm_naive(28851538, 1183019) == lcm_fast(28851538, 1183019));
    std::cout << "OK" << std::endl;
    return 0;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //numbers N;
  std::cout <<lcm_naive_2(a, b) << std::endl;
  //test();
  return 0;
}

