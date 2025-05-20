#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int slow_valid = 1;
        int begin = 1;
        int fast = 0;
        if(nums.size() == 0)
            return 0;
        while(fast < nums.size()){
            if()
        }
            
    }
};



int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{1,1,1,2,2,3};

    int k = solution.removeDuplicates(nums);
    std::cout << k << std::endl;
    for(auto &m:nums)
        std::cout << m <<" ";
    return 0;
}