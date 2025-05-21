#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> new_array(nums.size());
        for(int i=0;i<nums.size();++i){
            new_array[(i+k)%new_array.size()] = nums[i];
        }
        nums.assign(new_array.begin(), new_array.end());
    }
};




int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{8,8,7,7,7};

    solution.rotate(nums,6);
    // std::cout << k << std::endl;
    for(auto &m:nums)
        std::cout << m <<" ";
    return 0;
}
