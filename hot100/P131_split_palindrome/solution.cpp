#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>

using std::vector;
using std::string;
using std::queue;
using std::unordered_set;


class Solution {
public:
    string left, right;
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        result.reserve(s.length());
        process(result, path, s, 0);
        return result;
    }

    // 使用left作为result的索引
    void process(vector<vector<string>> &result, vector<string> &path, string s, int index){
        if(index >= s.length()){
            result.emplace_back(path);
            return ;
        }
        for(int i=1; i<=s.length(); ++i){
            index++;
            left = string(s.begin(), s.begin()+i);
            right = string(s.begin()+i, s.end());
            if(check(left))
                path.emplace_back(left);
            if(check(right))
                path.emplace_back(right);
            process(result, path, left, index+1);
            process(result, path, right, index+1);
            index--;
        }
    }

    bool check(string s){
        if(s=="") return false;
        for(int l_idx = 0, r_rdx = s.size()-1; l_idx<r_rdx; l_idx++, r_rdx--){
            if(s[l_idx] != s[r_rdx]){
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char **argv)
{
    Solution solution;
    string abc("aab");
    vector<vector<string>> result = solution.partition(abc);
    return 0;
}

