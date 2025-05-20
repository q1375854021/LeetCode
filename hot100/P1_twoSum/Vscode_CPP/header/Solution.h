#ifndef __SOLUTION_H
#define __SOLUTION_H

#include <vector>
#include <iostream>

using std::vector;



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=1;
        int L = nums.size();
        bool found = false;
        vector<int> result;
        while(nums[i]+nums[j] != target && j<=L){
            if(j==L){
                i++;
                j=i+1;
            }
            else{
                j++;
            }
        }
        if(j>=L) return result;
        result.emplace_back(i);
        result.emplace_back(j);
        return result;
    }
};


#endif