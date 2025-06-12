#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <string>
#include <algorithm>
#include <stack>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::cin;

class Solution {
public:
    bool isValid(string s) {
        stack<char> my_stack;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='('){
                my_stack.push(')');
            }
            else if(s[i]=='{'){
                my_stack.push('}');
            }
            else if(s[i]=='['){
                my_stack.push(']');
            }
            else if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(my_stack.empty()){
                    return false;
                }
                if(s[i] != my_stack.top()){
                    return false;
                }
                my_stack.pop();
            }
            else{

            }
        }
        if(!my_stack.empty()){
            return false;
        }
        return true;
    }
};

int main()
{   
    Solution solution;
    string str;
    int k;
    cin >> k >> str;
    solution.right_spin(str,k);
    cout << str << endl;
    return 0;
}
