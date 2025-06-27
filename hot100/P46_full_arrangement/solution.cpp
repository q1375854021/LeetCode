#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;

class Solution {
public:
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> walked(nums.size(),0);         // 走过的路径的index   走过的路径置为1
        vector<int> path;           // 当前的路径
        vector<vector<int>> result;
        backtrace(nums, &result, 0, path, walked);
        return result;
    }

    void backtrace(vector<int>& nums, vector<vector<int>> *result, int index, vector<int> &path, vector<int> &walked){
        if(index == nums.size()){
            result->emplace_back(path);
            return ;
        }
        for(int i=0; i<=nums.size()-1; i++){
            if(walked[i]==1){       // 如果是1，说明走过了
                continue;           
            }
            path.emplace_back(nums[i]);
            walked[i]=1;
            backtrace(nums, result, index+1, path, walked);
            path.pop_back();
            walked[i]=0;
        }
    }
};



int main(int argc, char **argv)
{
    vector<int> nums = {1,2,3};
    Solution solution;
    vector<vector<int>> result = solution.permute(nums);
    for(auto m:result){
        for(auto a:m){
            std::cout << a << " ";
        }
        std::cout <<"\n";
    }
}

