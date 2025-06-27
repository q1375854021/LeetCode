#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;



class Solution {
public:   

    // 二分查找，查找第一个>=的元素
    int binary_search(vector<int>& nums, int target){
        int left=-1, right = nums.size();
        int mid;
        while(left+1 != right){
            mid = (left + right)/2;
            if(nums[mid] < target){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return right;
    } 

    // 采用二分法最快， 因为是有序的
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1,-1};
        int length = nums.size();
        int left=-1,right=length;
        if(length == 0){
            return result;
        }
        left=binary_search(nums,target);
        right=binary_search(nums,target+1);
        if(left==right){
            return result;
        }
        else{
            result[0]=left;
            result[1]=right-1;
            return result;
        }
    }
};



int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{2,2};

    auto k = solution.searchRange(nums,3);
    for(auto &m:k)
        std::cout << m <<" ";
    return 0;
}

