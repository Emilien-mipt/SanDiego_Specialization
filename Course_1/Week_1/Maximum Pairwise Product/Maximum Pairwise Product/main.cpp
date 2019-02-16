//
//  main.cpp
//  Maximum Pairwise Product
//
//  Created by Emin Tagiev on 16/02/2019.
//  Copyright © 2019 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int max_num(vector<int>& num){
    int max_n = num[0];
    for(auto c:num){
        if(max_n < c) max_n = c;
    }
    return max_n;
}

unsigned long long MaxProductErase(vector<int>& num){
    vector<int> num_copy;
    for(int n:num) num_copy.push_back(n);
    unsigned long long first_max = max_num(num);
    //cout << "Maximum is " << max_num(arr_num) << endl;
    num_copy.erase(find(num_copy.begin(), num_copy.end(), first_max));
    //cout << "Maximum is " << max_num(arr_num) << endl;
    unsigned long long second_max = max_num(num_copy);
    return first_max * second_max;
}

unsigned long long MaxProductSort(vector<int>& num){
    sort(num.begin(), num.end());
    unsigned long long first_max = num[num.size()-1];
    unsigned long long second_max = num[num.size()-2];
    return first_max * second_max;
}

int main(int argc, const char * argv[]) {
    //Stress test for finding the bugs
    while(true){
        int n = rand()%4 + 2;
        cout << n << '\n';
        vector<int> a;
        for(int i = 0; i < n; i++) a.push_back(rand()%10);
        for(int n:a) cout << n << ' ';
        cout << endl;
        long long res_erase = MaxProductErase(a);
        long long res_sort = MaxProductSort(a);
        if(res_erase != res_sort) {
            cout << "Wrong answer: " << res_erase << " " << res_sort << endl;
            break;
        }
        else cout << "OK" << endl;
    }
    //Now the main part
    //Declare the variables
    int N = 0;
    int number = 0;
    cin >> N;
    vector<int> arr_num(N);
    //Fill the vector
    for(int i = 0; i < N; i++){
        cin >> number;
        arr_num[i] = number;
    }
    cout << MaxProductErase(arr_num) << endl;
    cout << MaxProductSort(arr_num) << endl;
    return 0;
}
