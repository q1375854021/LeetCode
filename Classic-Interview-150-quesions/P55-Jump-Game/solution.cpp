#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;



class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_can_index = 0;      // 表明最大的可达的坐标
        int i;
        int cur_can_index = 0;
        max_can_index = 0;
        for(i=0; i<nums.size(); ++i){
            if(i>max_can_index){
                return false;
            }
            cur_can_index = nums[i] + i;        //当前的值直接跳最多能到的步数
            if(cur_can_index > max_can_index){
                max_can_index = cur_can_index;   // 更新最大坐标
            }
        }
        return true;
    }
};


int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{2,0,0};

    int k = solution.canJump(nums);
    std::cout << k << std::endl;
    for(auto &m:nums)
        std::cout << m <<" ";
    return 0;
}
