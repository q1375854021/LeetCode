#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::unordered_map;



class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0, i = citations.size() - 1;
        while (i >= 0 && citations[i] > h) {
            h++;
            i--;
        }
        return h;
    }
};




int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums{1,3,1};

    int k=solution.hIndex(nums);
    std::cout << k << std::endl;
    for(auto &m:nums)
        std::cout << m <<" ";
    return 0;
}
