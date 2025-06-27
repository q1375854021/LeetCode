#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int total_profit = 0;
        for(i=1; i<prices.size(); ++i){
            if(prices[i]>prices[i-1]){
                total_profit+=(prices[i]-prices[i-1]);
            }
        }
        return total_profit;
    }
};



int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{2,4,1};

    int k = solution.maxProfit(nums);
    std::cout << k << std::endl;
    for(auto &m:nums)
        std::cout << m <<" ";
    return 0;
}


