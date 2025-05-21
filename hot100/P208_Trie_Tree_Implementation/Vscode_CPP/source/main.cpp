#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        int buy = prices[0];
        int i = 1;
        int max = 0;
        while(i != prices.size()){
            if(prices[i] < buy){
                buy = prices[i];
            }
            max = std::max(max, prices[i]-buy);
            i++;
        }
        return max;
    }
};

int main()
{   
    return 0;
}
