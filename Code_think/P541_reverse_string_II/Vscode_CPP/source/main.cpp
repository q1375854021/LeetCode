#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <string>


using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::string;
using std::endl;

class Solution {
public:
    int min(int a, int b){
        return a<b?a:b;
    }
    string reverseStr(string s, int k) {
        int length = s.size();
        int k_num = (length+k-1)/k;     // 向上取整
        int left = 0;
        int right = 0;
        char temp = 0;
        for(int k_index=0; k_index <= k_num-1; k_index++){
            if(k_index%2==0){
                left = k_index*k;
                right = min(left+k-1, s.size()-1);
                while(left < right){
                    temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;
                    left++;
                    right--;
                }
            }
        }
        return s;
    }
};

int main()
{   
    string s("abcdefg");
    Solution solution;
    s = solution.reverseStr(s, 2);
    cout << s << endl;
    return 0;
}
