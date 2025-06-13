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
    int lengthOfLongestSubstring(string s) {
        // 明确几个问题：
        // 1, 怎么判断某个字符和已有的字符串重复字符了    哈希map，顺便把位置信息也搞了
        // 2，重复之后，应该怎么移动，或者截取？   应当有位置信息, 在index的右侧进行截取
        // 3，区间怎么截取？ 快慢指针
        if(s.size()==0){
            return 0;
        }
        if(s.size()==1){
            return 1;
        }
        int slow = 0;
        int fast = 0;
        int length_max = 0;
        int length = 0;
        unordered_set<char> set;
        while(fast < s.size()){
            if(set.count(s[fast])==0 || fast == slow){
                set.insert(s[fast]);
                fast++;
                length = fast-slow;
            }
            else{
                length_max = length>length_max? length: length_max;
                slow++;
            }
        }
        length_max = length>length_max? length: length_max;
        return length_max;
    }
};


int main()
{   
    Solution solution;
    string input("au");
    cout << solution.lengthOfLongestSubstring(input);
    return 0;
}
