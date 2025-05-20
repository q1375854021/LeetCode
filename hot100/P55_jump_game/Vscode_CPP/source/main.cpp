#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1){
            return true;
        }
        if(nums[0]==0) return false;
        int last = nums.size() - 1;
        int i = 0;
        while(last > 0){
            while(last-i > 0){
                i++;
                if(last-i + nums[last-i] >= last){
                    last = last-i;
                    i=0;
                    break;
                }
            }
            if(last == i && last != 0){
                return false;
            }
        }
        return true;
    }
};

int main()
{   
    vector<int> nums = {1,0,1,0};
    Solution solution;
    bool can_jump = solution.canJump(nums);
    std::cout << can_jump;
    return 0;
}
