#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <iterator>  // 用于 std::advance

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;
using std::unordered_set;

class RandomizedSet {
public:
    unordered_set<int> set;
    std::pair<std::__detail::_Node_iterator<int, true, false>, bool> result;
    size_t result2;
    int i;

    RandomizedSet() {
    }
    
    bool insert(int val) {
        result = set.insert(val);        //插入value
        return result.second;     // 是1的话就是插入成功了。
    }
    
    bool remove(int val) {
        result2 = set.erase(val);       // 删除value
        return result2;                        // 大于0则说明删除成功
    }
    
    int getRandom() {
        i = rand() % set.size();
        auto it = set.begin();
        std::advance(it,i);
        return *it;
    }
};



int main(int argc, char **argv)
{
    RandomizedSet randomizedSet;
    bool k;
    int j;
    k = randomizedSet.remove(0);
    cout << k << endl;

    k = randomizedSet.remove(0);
    cout << k << endl;
    
    k = randomizedSet.insert(0);
    cout << k << endl;

    j = randomizedSet.getRandom();
    cout << j << endl;

    
    k = randomizedSet.remove(0);
    cout << k << endl;
    
    k = randomizedSet.insert(0);
    cout << k << endl;


    
    return 0;
}
