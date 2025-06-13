#include <exception>
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


class Solution {
public:
    // 成功
    bool repeatedSubstringPattern2(string s){
        return (s + s).find(s,1) != s.size();       // 如果字符串可重复，那么找到的坐标肯定是在前半区域，所以肯定是小于s.size的。   如果字符串不可重复，那么肯定只有在s.size()可以找到了。
    }
    // 成功
    bool repeatedSubstringPattern(string s) {
        if(s.size()<=1){
            return false;
        }
        // 先求最大公约数
        vector<int> common_divisor;
        for(int i=2; i<=s.size()/2+1; ++i){
            if(s.size()%i == 0){            // 是最大公约数
                common_divisor.push_back(i);
            }
        }
        // 考虑到质数的情况
        if(common_divisor.size()==0){
            for(int i=1; i<s.size(); ++i){
                if(s[0] != s[i]){
                    return false;
                }
            }
            return true;
        }

        int length = 0;             // 针对公约数i进行分割字符串，子字符串的长度
        char temp = 0;
        bool flag = true;
        for(auto i : common_divisor){
            flag = true;
            length = s.size()/i;
            for(int index = 0; index < length; index++){
                temp = s[index];
                for(int block=1; block < i; block++){
                    if(temp != s[block*length+index]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                return flag;
            }
        }
        return false;
    }

    // 下面是KMP解法，没搞出来
    bool repeatedSubstringPattern_backup(string s) {
        if(s.size()<=1){
            return true;
        }
        vector<int> next_array;
        Get_Next_Array(next_array, s);
        int len = s.size();
        if (len % (len - (next_array[len - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }
    
    void Get_Next_Array(vector<int> & next_array, const string &str){
        next_array.resize(str.size());
        if(str.size()==1){
            next_array[0] = -1;
            return ;
        }
        next_array[0]=-1;
        next_array[1]=0;
        int count = 0;
        int i = 2;
        while(i <= str.size()-1){
            if(str[i-1]==str[count]){
                count++;
                next_array[i]=count;
                i++;
            }
            else if(count > 0){
                count = next_array[count];
            }
            else{
                next_array[i]=0;
                i++;
            }
        }
    }
};
int main()
{   
    Solution solution;
    cout << solution.repeatedSubstringPattern("zzz");
    return 0;
}
