#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int slow = 0;
        int fast = 0;
        while(fast < nums.size())
        {
            if(nums[slow] != nums[fast]){       // 如果相等的话，fast后移
                nums[++slow] = nums[fast];
            }
            fast++;
        }
        return slow+1;       // 把index转化成number
    }
};



int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{1,1,2};

    int k = solution.removeDuplicates(nums);
    std::cout << k << std::endl;
    for(auto &m:nums)
        std::cout << m <<" ";
    return 0;
}