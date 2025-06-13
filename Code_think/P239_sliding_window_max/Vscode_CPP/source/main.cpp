#include <climits>
#include <deque>
#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::string;
using std::endl;
using std::stack;
using std::queue;
using std::deque;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {       // 如果q不为空，并且nums[i]比优先队列的最后一个值还要大，就把队列中最后位置的值弹出去。 因为最后的值肯定不可能称为最大值了。
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            // 重复处理。 
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);

            while (q.front() <= i - k) {                        // 如果队列的位置超出了滑动窗，直接就把滑动窗口的前面给弹出来了。
                q.pop_front(); 
            } 
            ans.push_back(nums[q.front()]);                     // 因为每次循环必定输出一次
        }
        return ans;
    }
};



int main()
{   
    Solution solution;
    vector<int> input{1,3,-1,-3,5,3,6,7};
    vector<int> output = solution.maxSlidingWindow(input, 3);
    for(auto m:output){
        cout << m << " ";
    }
    return 0;
}
