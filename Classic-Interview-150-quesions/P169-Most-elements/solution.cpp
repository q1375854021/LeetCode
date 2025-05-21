#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int winner = nums[0];
        for(int i=0; i<nums.size();++i){
            if(winner == nums[i]){
                count++;
            }
            else{
                if(count == 0){
                    winner = nums[i];
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return winner;
    }
};




int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{8,8,7,7,7};

    int k = solution.majorityElement(nums);
    std::cout << k << std::endl;
    for(auto &m:nums)
        std::cout << m <<" ";
    return 0;
}

/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int index = 0;
        int i = 0;
        int count = 0;
        int num = 0;
        for(index=0; index< nums.size(); ++index){
            num = nums[index];
            for(i=0; i<nums.size();++i){
                if(num == nums[i]){
                    count++;
                }
            }
            if(count > nums.size()/2){
                break;
            }else{
                count = 0;
            }
        }
        return num;
    }
};
*/