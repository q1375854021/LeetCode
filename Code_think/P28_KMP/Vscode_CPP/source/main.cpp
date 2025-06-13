#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <algorithm>
#include <unordered_set>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::endl;
using std::sort;
using std::unordered_set;
using std::string;


// KMP算法
class Solution {
public:
// 重点就是理解count的作用。count是i-1处的位置对应的next array值
    void getNext(vector<int> &next_array, const string & s){
        if(s.size()==1){
            next_array[0]=-1;
            return ;
        }
        // 第0个和第1个的next array一定是固定的
        next_array[0] = -1;
        next_array[1] = 0;
        // 然后从i=2这个位置开始
        int i = 2;
        int count = 0;    // count既是next array的值，也是上一个需要比对的坐标
        while(i <= s.size()-1){
            if(s[i-1]==s[count]){           
                count++;
                next_array[i]=count;
                i++; 
            }
            else if(count > 0){             // 如果不相等，那么就往前跳
                count = next_array[count];
            }
            else{       // 如果count都等于0了
                next_array[i]=0;
                i++;
            }
        }
    }

    // KMP算法
    int strStr(string main_str, string sub_str) {
        if(main_str.size()==0 || sub_str.size()==0 || sub_str.size() > main_str.size()){
                return -1;
            }
            int i1 = 0;         // main_str指针
            int i2 = 0;         // sub_str指针
            vector<int> next_array(sub_str.size());          // 创建sub_str的next_array
            getNext(next_array, sub_str);
            // 然后开始进行比较
            while(i1 <= main_str.size()-1 && i2 <= sub_str.size()-1){
                if(main_str[i1] == sub_str[i2]){
                    ++i1;
                    ++i2;
                }
                else if(next_array[i2]==-1){        // 说明当前main_str开头的字母中，没有匹配成功
                    ++i1;
                }
                else{
                    i2 = next_array[i2];
                }
            }
            if(i2 == sub_str.size()){
                return i1-i2;
            }
            return -1;
    }
};

int main()
{   
    Solution solution;
    string main_str("a");
    string sub_str("a");
    cout << solution.strStr(main_str, sub_str);
    return 0;
}
