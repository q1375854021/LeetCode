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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 开始排序
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){return a[0]<b[0];});
        for(int i=1; i<intervals.size(); ++i){
            if(intervals[i-1][1] >= intervals[i][0]){
                intervals[i-1][0] = std::min<int>(intervals[i-1][0], intervals[i][0]);
                intervals[i-1][1] = std::max<int>(intervals[i-1][1], intervals[i][1]);
                intervals.erase(intervals.begin()+i);

            }
       }     
        return intervals;   
    }
};

int main()
{   
    Solution solution;
    vector<vector<int>> intervals =  {{1,4},{0,2},{3,5},{15,18}};
    vector<vector<int>> result = solution.merge(intervals);
    for(auto m: result){
        for(auto n:m){
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
