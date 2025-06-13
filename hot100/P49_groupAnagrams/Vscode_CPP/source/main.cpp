#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>
#include <list>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::cin;
using std::queue;
using std::deque;
using std::unordered_map;



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 首先我要能分解每个单次
        unordered_map<string, string> maps;    // key: 原始单词：   value：字典序单词
        unordered_map<string, vector<string>> maps_result;    // key:字典序单词，  value，字典序对应的单词集合

        // 初始化maps和maps_result;
        string dic_str;
        for(auto str: strs){
            dic_str = str;
            sort(dic_str.begin(), dic_str.end());
            maps[str] = dic_str;      // 字典序排序
            maps_result[dic_str].push_back(str);
        }
        // 其次我要能比对每个单次是否是字母异位词语，
        // 怎么比对呢？把单次按照字典序重排我觉得就行

        // 存储结果
        vector<vector<string>> result;
        for(auto m: maps_result){
            result.emplace_back(m.second);
        }
        return result;
    }
};

int main()
{   
    Solution solution;
    vector<string> input{"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = solution.groupAnagrams(input);
    for(auto m: result){
        for(auto n:m){
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
