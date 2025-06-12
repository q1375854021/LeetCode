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


class Solution {
public:
    int maxArea(vector<int>& height) {
        int capacity_max = 0;
        int left = 0;
        int right = height.size()-1;
        capacity_max = calculate_capacity(height, left, right);
        int capacity_new = 0;
        while(left < right){
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
            capacity_new = calculate_capacity(height, left, right);
            capacity_max = capacity_max>capacity_new ? capacity_max:capacity_new;
        }
        return capacity_max;
    }

    int calculate_capacity(vector<int>& height, int left, int right){
        int width = (right-left);
        int hei = min(height[left], height[right]);
        return width*hei;
    }
};



int main()
{   
    std::vector<int> height{1,3,2,5,25,24,5};
    Solution solution;
    cout << solution.maxArea(height);
    return 0;
}
