#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>


using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        process(result, path, 0, 0, 0, n);
        return result;
    }


    // result用来存放最终的结果
    // path用来存放当前的路径
    // index用来表示当前正在处理的位置坐标、
    // opennum表示左括号的数量
    // closenum表示右括号的数量
    // n表示n个括号。
    void process(vector<string> &result, string& path, int index, int opennum, int closenum, int n){
        if(index == 2*n){
            result.emplace_back(path);
            return ;
        }
        if(opennum < n){
            path.push_back('(');
            process(result, path, index+1, opennum+1, closenum, n);
            path.pop_back();
        }
        if(closenum < opennum){
            path.push_back(')');
            process(result, path, index+1, opennum, closenum+1, n);
            path.pop_back();
        }
    }
};


int main(int argc, char **argv)
{
    Solution solution;
    vector<string> result = solution.generateParenthesis(3);
    for(auto m:result){
        for(auto a:m){
            std::cout << a;
        }
        std::cout << "\n";
    }
    return 0;
}

