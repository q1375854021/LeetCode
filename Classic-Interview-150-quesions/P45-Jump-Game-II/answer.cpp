#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;



// 也是采用贪心算法
class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_jump = nums[0];        // 当前能跳到的最大坐标
        int cur_index = 0;       // 对应的index
        int max_index = 0;
        int max_jump = nums[0];
        int step = 0;              // 所需要的步数
        int i = 0; 
        bool exit_flag = false;            // 为1的时候退出循环
        if(nums.size()<=1){
            return 0;
        }
        else if(i+nums[i]>=nums.size()-1){
            return 1;
        }
        while(!exit_flag){
            for(i=cur_index; i<=cur_index+nums[cur_index]; ++i){
                if(i+nums[i] > max_jump){
                    max_index = i;
                    max_jump = i+nums[i];
                    if(max_jump >= nums.size()-1){
                        step++;
                        exit_flag = true;
                        break;
                    }
                }
            }
            cur_index = max_index;
            cur_jump = max_jump;
            step++;
        }
        return step;
    }
};


int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{3,4,3,1,0,7,0,3,0,2,0,3};

    int k = solution.jump(nums);
    std::cout << k << std::endl;
    for(auto &m:nums)
        std::cout << m <<" ";
    return 0;
}
