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

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int mul = 1;
        int count = 0;
        for(right=0; right < nums.size(); right++){
            mul = mul * nums[right];
            while(mul >= k && left<right){
                mul = mul/nums[left];
                left++;
            }
            // 现在就得到了一组满足要求的最大范围
            if(mul < k)
                count += (right-left+1);
        }
        return count;
    }

    int numSubarrayProductLessThanK2(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int mul = 1;
        int count = 0;
        for(left=0; left<nums.size(); ++left){
            mul = 1;
            for(right=left; right< nums.size(); ++right){
                mul = mul * nums[right];
                if(mul < k){
                    ++count;
                }
            }
        }
        return count;
    }
};



int main()
{   
    std::vector<int> num{1,2,3};
    Solution solution;
    cout << solution.numSubarrayProductLessThanK(num, 0);
    return 0;
}
