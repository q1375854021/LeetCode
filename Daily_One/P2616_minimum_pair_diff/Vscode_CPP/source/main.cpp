#include <iostream>
#include <tuple>
#include <vector>
#include <numeric>
#include <list>
#include <algorithm>
#include <unordered_set>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::endl;
using std::sort;
using std::unordered_set;
using std::tuple;
using std::make_tuple;
using std::get;
using std::pair;


class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<pair<int,int>> array(nums.size());                    // first是原始数值，second是坐标, third是差值
        for(int i=0; i<nums.size(); ++i){
            array[i].first = nums[i];
            array[i].second = i;
        }
        // 开始进行排序
        sort(array.begin(), array.end());

        // 开始贪心计算
        

    }
};


int main()
{   
    std::vector<int> num{-2,0,1,1,2};
    Solution solution;
    vector<vector<int>> result = solution.threeSum(num);
    for(auto m: result){
        for(auto a:m){
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}
