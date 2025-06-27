#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

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
using std::queue;
using std::deque;



class Solution {
public: 
    vector<int> path;
    vector<vector<int>> result;

    vector<vector<int>> combine(int n, int k) {
        process(n,k,1);
        return result;
    }

    void process(int n, int k, int start){
        if(path.size()==k){
            result.emplace_back(path);
            return ;
        }
        // 得到当前递归节点的数据
        for(int i=start;i<=(n-(k-path.size()))+1; ++i){
            path.emplace_back(i);
            process(n,k,i+1);
            path.pop_back();
        }
    }
};

int main()
{   
    Solution solution;
    vector<vector<int>> result = solution.combine(4, 2);
    for(auto m: result){
        for(auto n: m){
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
