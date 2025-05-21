#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0){
            return ;
        }
        if(k>nums.size()){
            k = k%nums.size();
        }
        vector<int> temp(nums.end()-k,nums.end());        //使用迭代器，将原来的k个多余的拷贝到新的vector
        for(int i=nums.size()-1; i>=k;--i){
            nums[i] = nums[i-k];
        }
        std::copy(temp.begin(), temp.end(), nums.begin());
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
