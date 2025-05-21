#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::unordered_map;



class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        unordered_map<int,int> count;
        int sum = 0;
        int h=0;
        bool loop = true;
        unordered_map<int,int>::iterator it;
        for(int i=0; i<length; ++i){  //使用哈希，表示为  被引次数->论文个数
            ++count[citations[i]];
        }

        sum = 0;
        for(h=length; h>=0; --h){
            for(it = count.begin(); it != count.end(); ++it ){
                if(it->first >= h){       // 如果被引次数 >= 选定的h
                    sum += it->second;    //那么就把被引次数对应的论文数量求和
                    // count.erase(it);     // 防止重复遍历，删除掉it指定的哈希对 // 不要在遍历中进行删除，会导致it失效
                }     
            }
            if(sum >= h){            // 如果被引次数大于等于h
                loop = false;
            }
            sum = 0;
            if(!loop){
                break;
            }
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
