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
    int subarraySum(vector<int>& nums, int k) {
        // 移动窗口进行处理
        // 如果sum < k, 那么右指针右移
        // 如果sum > k， 那么左指针右移
        // 什么时候终止呢？ 右指针==nums.size()时候就终止
        int left = 0;
        int right = 0;
        int count = 0;
        int sum = 0;
        for(right=0; right < nums.size(); ++right){
            sum += nums[right];
            while(sum > k && left < right){
                sum -= nums[left];
                left++;
            }
            if(sum == k){
                count++;
            }
        }
        return count;
    }
};



int main()
{   
    std::vector<int> num{-1,-1,1};
    Solution solution;
    int result = solution.subarraySum(num,0);
    cout << result;
    return 0;
}
