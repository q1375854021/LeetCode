#include <iostream>
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

// 自定义哈希函数
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 因为不要求顺序，我直接进行排序
        sort(nums.begin(), nums.end());
        unordered_set<vector<int>, VectorHash> result_set;
        vector<int> temp_result;
        int left = 0;
        int right = 0;
        int sum = 0;
        for(int i=0; i<=nums.size()-3; ++i){
            left = i+1;
            right = nums.size()-1;
            while(left < right){
                sum = nums[i]+nums[left]+nums[right];
                if(sum > 0){
                    right--;
                }
                else if(sum == 0){
                    temp_result.push_back(nums[i]);
                    temp_result.push_back(nums[left]);
                    temp_result.push_back(nums[right]);
                    result_set.insert(temp_result);
                    temp_result = {};
                    left++;
                }
                else{
                    left++;
                }
            }
        }
        vector<int> res;
        vector<vector<int>> result;
        for(auto m: result_set){
            result.emplace_back(m);
        }
        return result;
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
