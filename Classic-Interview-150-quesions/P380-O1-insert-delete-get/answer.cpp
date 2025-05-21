#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>
#include <iterator>  // 用于 std::advance

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int,int> set;
    int i;

    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(set[val] != 0){
            return false;
        }
        else{
            vec.push_back(val);       // 直接push_back
            set[val]=vec.size();     // 存入这个 存的是index+1
            return true;
        }
    }
    
    bool remove(int val) {
        if(set[val] == 0){
            return false;
        }
        else{
            vec.at(set[val]-1) = vec.at(vec.size()-1);     // 把最后一行的拷贝过来
            set[vec.at(vec.size()-1)] = set[val];        // 最后一行的index变成了当前的index
            vec.pop_back();                              // 其他的index不变
            set.erase(val);                             // 把最后一个数的哈希删掉
            return true;
        }
    }
    
    int getRandom() {
        i = rand() % vec.size();
        return vec.at(i);
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
