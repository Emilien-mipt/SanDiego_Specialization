#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <stack>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {

  public:

    void Push(int value) {
        stack.push_back(value);
        if(stack.size()==1) max_pointers.push(value);
        else{
           if(value >= max_pointers.top()) max_pointers.push(value);          
        }
    }

    void Pop() {
        assert(stack.size());
        if(stack[stack.size()-1] == max_pointers.top()) max_pointers.pop();
        stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        return max_pointers.top();
    }
    
  private:
    vector<int> stack;
    std::stack<int> max_pointers;
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
