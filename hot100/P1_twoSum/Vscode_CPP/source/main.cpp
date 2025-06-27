#include <iostream>
#include <vector>
#include "Solution.h"
int main()
{   
    Solution solution;
    std::vector<int> nums = {2,5,5,11};
    std::vector result = solution.twoSum(nums,10);
    for(auto m:result){
        std::cout << m << " ";
    }

    return 0;
}
