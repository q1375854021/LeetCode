#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
using std::unordered_set;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        // 既然是连续长度，必然有类似链表的结构

        // 如何定义头节点？ 使用哈希表
        unordered_map<int, int> map;        // key: 当前树    value：头节点
        unordered_set<int> set;             // 用来存放处理过的数据
        // 首先把所有东西放在哈希表里   去重
        for(auto m : nums){
            map[m]=m;                      // 生成头节点
        }

        // 如何按顺序插入， 按照哈希表查询
        int head = 0;
        int max_length = INT_MIN;
        for(auto m : nums){
            head = m;
            while(map.find(head-1) != map.end()){
                head = head-1;
            }
            // 把head到m上的所有路径都设为head
            for(int i=m; i>=head; --i){
                if(set.find(i) == set.end()){
                    map[i] = head;
                    set.insert(i);
                }
                else{
                    break;
                }
            }
            if(m-map[m]+1 > max_length){
                max_length = m-map[m] + 1;
            }
        }
        return max_length;
    }
};

int main()
{   
    Solution solution;
    vector<int> input{0,3,7,2,5,8,4,6,0,1};
    cout << solution.longestConsecutive(input);
    return 0;
}
