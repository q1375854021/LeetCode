#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> walked;
        vector<int> path;
        process(&result, nums, 0, walked, path);
        return result;
    }

    long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
    }

    void process(vector<vector<int>> *result, vector<int>& nums, int result_size, vector<int> &walked,vector<int> &path){
        // 把result_size前面的标记上
        for(int i=0; i<nums.size(); ++i){
            if(i < result_size)
                walked[i] = 1;
            else
                walked[i] = 0;
        }
        if(result_size==0){
            result->emplace_back(path);
            process(result, nums, result_size+1, walked, path);
        }
        else{
            for(int i=0; i<factorial(result_size);++i){
                if(walked[i]==1){
                    continue;
                }
                walked[i]=1;
                path.emplace_back(nums[i]);
                result->push_back(path);
                process(result, nums, result_size+1, walked, path);
                walked[i]=0;
                path.pop_back();
            }
        }
    }
};



int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{1,2,3};

    vector<vector<int>> result = solution.subsets(nums);
    for(auto m:result){
        for(auto a:m){
            std::cout << a << " ";
        }
        std::cout <<"\n";
    }
    return 0;
}

