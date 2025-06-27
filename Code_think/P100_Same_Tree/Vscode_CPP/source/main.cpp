#include <cstdlib>
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
//  || tokens[i]=="-" || tokens[i]=="*" || tokens[i] == "/"
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;
        int operate_left = 0;
        int operate_right = 0;
        for(int i=0; i<=tokens.size()-1; ++i){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i] == "/"){
                operate_right = values.top();
                values.pop();
                operate_left = values.top();
                values.pop();
                if(tokens[i]=="+") values.push(operate_left+operate_right);
                else if(tokens[i]=="-") values.push(operate_left-operate_right);
                else if(tokens[i]=="*") values.push(operate_left*operate_right);
                else values.push(operate_left/operate_right);
            }
            else{
                values.push(std::stoi(tokens[i]));
            }
        }
        return values.top();
    }
};


int main()
{   
    Solution solution;
    vector<string> input{"4","13","5","/","+"};
    int result = solution.evalRPN(input);
    cout << result << endl;
    return 0;
}
