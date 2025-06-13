#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <string>
#include <algorithm>
#include <stack>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::cin;

class Solution {
public:
    void right_spin(string &s, int k) {
        k = k % s.size();       // 防止k越界
        swap(s,0,s.size()-1);
        swap(s, 0, k-1);
        swap(s, k, s.size()-1);
    }

    void swap(string &s, int left, int right){
        char temp = 0;
        while(left < right){
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

int main()
{   
    Solution solution;
    string str;
    int k;
    cin >> k >> str;
    solution.right_spin(str,k);
    cout << str << endl;
    return 0;
}
