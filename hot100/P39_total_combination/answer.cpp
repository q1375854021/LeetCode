#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;           // path[0] 就是 路径的综合，  path[1] 开始才算路径
        vector<vector<int>> result; // 用于存放结果
        path.emplace_back(0);
        process(result, path, 0, candidates, target);
        return result;
    }

    // result用于存放结果   path用于存放符合结果的组合，  index表示当前正在处理第几位，因为结果都是有序的，所以需要index。 
    void process(vector<vector<int>> &result, vector<int> &path,int index, vector<int>& candidates, int target){
        if(path[0] >= target){
            if(path[0] == target)
                result.emplace_back(path.begin()+1, path.end());
            return ;
        }
        for(int i=index; i<candidates.size(); ++i){
            path[0] = path[0] + candidates[i];
            path.emplace_back(candidates[i]);
            process(result, path, i, candidates, target);
            path[0] = path[0] - candidates[i];
            path.pop_back();
        }
    }
};



int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{2,3,5};
    vector<vector<int>> result = solution.combinationSum(nums, 8);
    for(auto m:result){
        for(auto a:m){
            std::cout << a << " ";
        }
        std::cout <<"\n";
    }
    return 0;
}

