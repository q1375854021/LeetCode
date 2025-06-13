#include <cstddef>
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
using std::unordered_map;
using std::unordered_set;       

class RandomizedSet {
public:
    unordered_map<int , int > forward_map;          // value   index  
    unordered_map<int , int > back_map;             // index   value
    int size = 0;                                       // size，用于取随机数

    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(forward_map.find(val) != forward_map.end() ){            // 如果找到val了
            return false;
        }
        forward_map[val] = size;                // 插到末尾
        back_map[size] = val;                   // 两个map
        size++;
        return true;
    }
    
    bool remove(int val) {
        // 末尾是   back_map[size-1]   ->   tail value        删除的元素是  forward[val]  -> cur_index
        if(forward_map.find(val) == forward_map.end() ){            // 如果没找到val  
            return false;
        }
        
        // 把最后一个元素的index更新到当前val对应的index
        int val_index = forward_map[val];
        int last_val = back_map[size-1];
        forward_map[last_val] = val_index;
        back_map[val_index] = last_val;
        forward_map.erase(val);
        back_map.erase(size-1);
        size--;
        return true;
    }
    
    int getRandom() {
        if(size == 0){
            return NULL;
        }
        int i = rand() % size;
        return back_map[i];
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
