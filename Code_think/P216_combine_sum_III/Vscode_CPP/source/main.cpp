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
    vector<vector<int>> result;
    vector<int> path;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45){
            return {};
        }
        // min sum calculate
        if(k*(k+1>>1) > n){
            return {};
        }
        int sum = 0;
        process(k, n, 1, sum);
        return result;
    }

    void process(int k, int n, int start, int sum){
        if(sum > n){
            return ;
        }
        if(sum == n && path.size()==k){
            result.emplace_back(path);
            return ;
        }
        if(path.size()==k && sum < n){
            return ;
        }
        for(int i=start; i<=std::min<int>(9,(n-(k-path.size()) + 1)); ++i){
            sum += i;
            path.emplace_back(i);
            process(k, n, i+1, sum);
            path.pop_back();
            sum -= i;
        }
    }
};


int main()
{   
    Solution solution;
    vector<vector<int>> result = solution.combinationSum3(2,18);
    for(auto m: result){
        for(auto n: m){
            cout << n << " ";
        }
        cout << endl;
    }
    cout << " test suceess! "<< endl;
    return 0;
}
