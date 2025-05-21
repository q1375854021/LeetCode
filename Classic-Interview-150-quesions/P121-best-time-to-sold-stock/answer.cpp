#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> hash_count;   // 哈希表初始化时，默认值为0
        int cnt = 0, majority = 0;                 // cnt表示多数元素的存储个数，majority多数元素的值
        for(int i=0; i<nums.size(); ++i){
            hash_count[nums[i]]++;
            if(hash_count[nums[i]] > cnt){
                majority = nums[i];
                cnt = hash_count[nums[i]];
            }
        }
        return majority;
    }
};


/*
// 同归于尽消杀法
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
*/



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
