#include <vector>


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 定义初始状态
        int dp_prev = nums[0];
        int dp_cur = 0;
        // 状态转移
        int result = nums[0];
        for(int i=1; i<nums.size(); ++i){
            dp_cur = max(dp_prev + nums[i], nums[i]);
            if(dp_cur > result){
                result = dp_cur;
            }
        }
        return dp_cur;
    }
};


int main(){
    Solution solution;
    solution.removeElement_test();
    return 0;
}