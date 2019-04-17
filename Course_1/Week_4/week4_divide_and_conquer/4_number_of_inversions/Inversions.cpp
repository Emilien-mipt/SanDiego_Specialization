//Count the number of invertions
#include <iostream>
#include <vector>
#include<algorithm>

class Solution{
public:
    void Mergesort(long long& count, std::vector<int>& array){
        std::vector<int> temp(array.size());
        mergesort(count, array, temp, 0, array.size()-1);
    }
    
    void mergesort(long long& count, std::vector<int>& array, std::vector<int>& temp, int leftStart, int rightEnd){
        if(leftStart >= rightEnd) return;
        int middle = (leftStart + rightEnd)/2;
        mergesort(count, array, temp, leftStart, middle);
        mergesort(count, array, temp, middle+1, rightEnd);
        mergeHalves(count, array, temp, leftStart, rightEnd);
    }
    
    void mergeHalves(long long& count, std::vector<int>& array, std::vector<int>& temp, int leftStart, int rightEnd){
        int leftEnd = (leftStart + rightEnd)/2;
        int rightStart = leftEnd + 1;
        int left = leftStart;
        int right = rightStart;
        int index = leftStart;
        
        while(left <= leftEnd && right <=rightEnd){
            //Compare the elements of the left and right halves and copy in the temp vector
            if(array[left] <= array[right]){
                temp[index] = array[left];
                left++;
            }
            else{
                temp[index] = array[right];
                right++;
                count += leftEnd - left + 1;
            }
            index++;
        }
        // Insert all the remaining values into temp[].
        while(left<=leftEnd){ //from the left side
            temp[index] = array[left];
            left++;
            index++;
        }
        
        while(right<=rightEnd){ //from the right side
            temp[index] = array[right];
            right++;
            index++;
        }
        
        //Fill the value from temp back to array
        for(int i = leftStart; i<=rightEnd; i++) array[i] = temp[i];
    }
};


int main(){
    int n = 0;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int& element:arr) std::cin >> element;
    
    long long count = 0;
    Solution sol;
    sol.Mergesort(count, arr);
    std::cout << count << std::endl;
}

