#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i = 0;
        for (int num : nums) {
           if (i < 2 || num > nums[i - 2]) {
               nums[i++] = num;
           }
       }
       
       return i;
    }
};



int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{1,1,1};

    int k = solution.removeDuplicates(nums);
    std::cout << k << std::endl;
    for(auto &m:nums)
        std::cout << m <<" ";
    return 0;
}