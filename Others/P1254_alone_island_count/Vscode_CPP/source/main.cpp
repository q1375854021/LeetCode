#include <iostream>
#include <vector>
#include <numeric>

using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::endl;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int result_all = accumulate(nums.begin(), nums.end(),0);
        int result = proccessA(nums, 0, nums.size()-1);
        cout << result << endl;
        if(result >= result_all-result){
            return true;
        }
        return false;
    }

    void proccessA(vector<int>& nums,int left,int right, int &Anum, int &Bnum){
        if(left == right){
            Anum += nums[left];
        }
        proccessB(nums, left+1, right, Anum, Bnum);

        proccessB(nums, left, right-1, Anum, Bnum);
        right_val = right_val + (nums[right]);
        return max( left_val, right_val);

    }
    void proccessB(vector<int>& nums,int left,int right,int &Anum, int &Bnum){
        if(left == right){
            Bnum += nums[left];
        }
        int left_val = proccessA(nums, left+1, right, Anum, Bnum);
        left_val = left_val + (nums[left]);

        int right_val = proccessA(nums, left, right-1, Anum, Bnum);
        right_val = right_val + (nums[right]);
        return min( left_val, right_val);
    }
};

int main()
{   
    std::vector<int> num{1,5,2};
    Solution solution;
    bool result = solution.predictTheWinner(num);
    std::cout << result;
    return 0;
}
