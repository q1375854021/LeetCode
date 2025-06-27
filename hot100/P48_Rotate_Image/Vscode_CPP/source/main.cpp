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
    void rotate(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        int temp = 0;
        for(int i=0; i<height-1; i++){
            for(int j=i+1; j<width; j++){
                temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
        // 然后镜像对称
        for(int i=0; i<height; i++){
            for(int j=0; j<width/2; ++j){
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][width-1-j];
                matrix[i][width-1-j] = temp;
            }
        }
    }
};



int main()
{   
    Solution solution;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    solution.rotate(matrix);
    for(auto m: matrix){
        for(auto n: m){
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
