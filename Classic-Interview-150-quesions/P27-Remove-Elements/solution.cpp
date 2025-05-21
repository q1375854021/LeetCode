#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0; 
        int right = nums.size();
        while(left < right){
            if(nums[left] == val){
                nums[left] = nums[right - 1];
                right--;
            }
            else{
                left++;
            }
        }
        return left;
    }
};


int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{3,3};
    int val = 3;

    int k = solution.removeElement(nums,val);
    std::cout << k << std::endl;
    for(auto &m:nums)
        std::cout << m <<" ";
    return 0;
}