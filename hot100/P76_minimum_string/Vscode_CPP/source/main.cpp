#include <climits>
#include <iostream>
#include <unordered_map>
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
using std::unordered_map;


class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        // 总体思路是滑动窗口
        // 匹配原则是字符数组匹配
        // 移动原则是从一个满足要求的窗口，到另一个满足要求的窗口
        int left = 0;
        int next_left = 0;
        int right = 0;

        int left_begin = 0;
        int right_end = 0;

        // target  t的哈希表
        vector<int> target_map('z'-'A'+1, 0);
        vector<int> source_map('z'-'A'+1, 0);
        for(auto m: t){
            target_map[m-'A']++;
        }

        // 开始进行匹配
        
        string temp_result;

        // 找到第一个匹配的单词
        int length = INT_MAX;
        left = find_first(target_map, s, 0);

        // 然后开始加入哈希表
        for(right = left; right<s.size(); ++right){
            source_map[s[right]-'A']++;
            while(compare(source_map, target_map, t) && next_left != -1){
                if(length > right-left+1){
                    left_begin = left;
                    right_end = right+1;
                    // temp_result = string(s.begin()+left_begin, s.begin()+right_end);
                    length = right-left+1;
                }
                // 找到下一个符合条件的坐标
                next_left = find_first(target_map, s, left+1);
                // 处理原来的hashmap
                if(next_left != -1){
                    for(int i=left; i<next_left; ++i){
                        source_map[s[i]-'A']--;
                    }
                    left = next_left;
                }
            }
        }
        return string(s.begin()+left_begin, s.begin()+right_end);
    }

    bool compare(vector<int> &source_map, vector<int> &target_map,  string &t){
        for(auto m: t){
            if(source_map[m-'A']<target_map[m-'A']){
                return false;
            }
        }
        return true;
    }

    // 使用这个函数之前，target_map必须初始化好
    int find_first(vector<int> &target_map, string &s, int begin_index){
        for(int i=begin_index; i<s.size(); ++i){
            if(target_map[s[i]-'A']!=0){
                return i;
            }
        }
        return -1;
    }

};



int main()
{   
    Solution solution;
    string s("ADOBECODEBANC");
    string t("ABC");
    cout << solution.minWindow(s, t);
    return 0;
}
