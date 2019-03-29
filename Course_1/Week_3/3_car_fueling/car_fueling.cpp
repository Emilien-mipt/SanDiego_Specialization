#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::endl;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int count = 0;
    int position = 0;
    int m = tank;

    stops.push_back(dist);

    vector<int> dist_stops;
    dist_stops.push_back(stops[0]);

    for(int i=0; i<stops.size()-1; i++){
        dist_stops.push_back(stops[i+1]-stops[i]);
    }

    int i = 0;
    while(i < dist_stops.size()){
        if(dist_stops[i] <=  m){
           position += dist_stops[i];
           m -= dist_stops[i];
           i++;
        }
        else{
	   m = tank;
           count++;
           if(m < dist_stops[i]) return -1;
        }
    }
    return count;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
