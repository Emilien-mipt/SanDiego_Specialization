#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int last_digit(const int& a){
    return a%10;
}

int last_digit_sum(const int& a, const int& b){
    int res = 0;
    if(a+b >= 10)
        res = (a+b) - 10;
    else
        res = a+b;
    return res;
}

int get_fibonacci_last_digit_fast(const int& n){
    int res = 0;
    if(n == 0) res = n;
    else{
        std::vector<int> fib(n+1);
        fib[0] = 0;
        fib[1] = 1;
        for(int i=2; i<n+1; i++){
            int current = last_digit_sum(last_digit(fib[i-1]), last_digit(fib[i-2]));
            fib[i] = current;
        }
        res = fib[n];
    }
    return res;
}

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    long long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    return current % 10;
}

void test_solution() {
    assert(get_fibonacci_last_digit_fast(3) == 2);
    assert(get_fibonacci_last_digit_fast(331) == 9);
    for (int n = 0; n < 20; ++n){
        assert(get_fibonacci_last_digit_naive(n) == get_fibonacci_last_digit_fast(n));
    }
}

int main() {
    int n;
    cin >> n;
    //int c = get_fibonacci_last_digit_fast(n);
    //cout << c << '\n';
    //test_solution();
    int c = get_fibonacci_last_digit_fast(n);
    cout << c << '\n';
    }
