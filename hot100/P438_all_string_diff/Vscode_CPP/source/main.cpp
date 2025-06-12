#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <algorithm>
#include <unordered_set>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::endl;
using std::sort;
using std::unordered_set;
using std::string;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()){
            return {};
        }
        int target_length = p.size();
        int target_val = 0;
        vector<int> target_size(26,0);
        for(auto m: p){
            target_size[m-'a']++;
        }
        
        // 开始比对
        vector<int> cur_size(26,0);
        for(int i=0; i<p.size(); ++i){
            cur_size[s[i]-'a']++;
        }

        vector<int> result;
        if(cur_size == target_size){
            result.push_back(0);
        }
        for(int i=1; i<=s.size()-p.size(); ++i){
            cur_size[s[i-1]-'a']--;
            cur_size[s[i+p.size()-1]-'a']++;
            if(cur_size == target_size){
                result.push_back(i);
            }
        }
        return result;
    }
};



int main()
{   
    std::vector<int> num{-2,0,1,1,2};
    Solution solution;
    vector<vector<int>> result = solution.threeSum(num);
    for(auto m: result){
        for(auto a:m){
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}
