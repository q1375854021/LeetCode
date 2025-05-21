#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0];
        int i = 0;
        int max_profit = 0;
        for(int i=0; i<prices.size(); ++i){
            if(prices[i]<low){
                low = prices[i];
            }
            else{
                if(prices[i]-low > max_profit){
                    max_profit = prices[i]-low;
                }
            }
        }
        return max_profit;
    }
};



int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{7,1,5,3,6,4};

    int k = solution.maxProfit(nums);
    std::cout << k << std::endl;
    for(auto &m:nums)
        std::cout << m <<" ";
    return 0;
}
