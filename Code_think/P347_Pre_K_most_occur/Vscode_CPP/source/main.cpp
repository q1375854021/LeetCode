#include <ios>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
#include <numeric>
#include <list>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::endl;
using std::priority_queue;
using std::unordered_map;
using std::pair;

struct CMP{
    bool operator()(pair<int, int>&a, pair<int, int> &b){
        return a.second < b.second;
    }
};

class Solution {
public:


    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> item_counts;
        for(auto m: nums){
            item_counts[m]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, CMP> result_queue(item_counts.begin(), item_counts.end());
        vector<int> results;
        for(int i=0; i<k; ++i){
            results.push_back(result_queue.top().first);
            result_queue.pop();
        }
        return results;

    }
};


int main()
{   
    std::vector<int> num{1,1,1,2,2,3};
    Solution solution;
    vector<int> result = solution.topKFrequent(num, 2);
    for(auto m: result){
        cout <<  m << "  ";
    }
    return 0;
}
