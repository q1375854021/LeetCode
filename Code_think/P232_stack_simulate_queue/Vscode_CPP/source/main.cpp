#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <string>
#include <stack>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::string;
using std::endl;
using std::stack;

class MyQueue {
public:
    stack<int> in_stack;
    stack<int> out_stack;

    MyQueue() {

    }
    
    void push(int x) {
        in_stack.push(x);
    }
    
    int pop() {
        int value = peek();
        out_stack.pop();
        return value;
    }
    
    int peek() {
        if(out_stack.empty()){
            while(!in_stack.empty()){
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        int value = out_stack.top();
        return value;
    }
    
    bool empty() {
        return (in_stack.empty()&&out_stack.empty());
    }
};

int main()
{   
    string s("abcdefg");
    Solution solution;
    s = solution.reverseStr(s, 2);
    cout << s << endl;
    return 0;
}
