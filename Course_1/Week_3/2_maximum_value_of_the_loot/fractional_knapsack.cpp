#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <exception>
#include <iomanip>

using std::vector;

int sum_weights(const vector<int> weights){
	int sum = 0;
	for(int n:weights) sum+=n;
	return sum;
}

int max_weight(vector<int>& values, vector<int>& weights){
	int max_index = 0;
	double max_vw = 0.;
      for(int i=0; i<values.size(); i++){ 
          double vw = (double)values[i]/weights[i];
		      if(weights[i] != 0 && vw > max_vw) {
			       max_vw = vw;
             max_index = i;
		      }
      }
	return max_index;
}


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {

  double value = 0.0;

  // write your code here
  int W = 0;
  if(sum_weights(weights) <= capacity){
  	for(int v: values) value += v;
  }
  else{
     while(W < capacity){
        int max_index = max_weight(values, weights);
        int max_weight =  weights[max_index];
        //std:: cout << "Max_weight: " << max_weight << std:: endl;
        if(max_weight <= (capacity-W)){
		            W += max_weight;
                value += values[max_index];
                weights.erase(weights.begin()+max_index);
                values.erase(values.begin()+max_index);
        }
        else{
                //std:: cout << "Difference: " << capacity-W << std:: endl;
	   	          double ratio = double(capacity-W)/max_weight;
                //std::cout << "Ratio: " << ratio << std::endl;
                W += (capacity-W);
                max_weight -= (capacity-W);
                value += ratio*values[max_index];
                values[max_index] -= ratio*values[max_index];	
        }
        //std::cout << "W: " << W << std::endl;
        //std::cout << "Value: " << value << std::endl;
     }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  //std::cout << std::fixed << std::setprecision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}
