#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

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
using std::queue;
using std::deque;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 对角线确定区域
        int i = 0, j=matrix[0].size()-1;
        while(i<=matrix.size()-1 && j>=0){
            if(matrix[i][j] > target){
                j--;
            }
            else if(matrix[i][j] < target){
                i++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};


int main()
{   
    Solution solution;
    
    cout << result << endl;
    cout << " test suceess! "<< endl;
    return 0;
}
