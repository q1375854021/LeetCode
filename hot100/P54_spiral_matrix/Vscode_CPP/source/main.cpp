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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        vector<int> result;
        int direction = 'd';    // 
        int d_bound = width-1;
        int a_bound = 0;
        int w_bound = 1;
        int s_bound = height-1;

        int x = 0, y = 0;
        for(int i=0; i<height*width; ++i){
            // add to buffer first
            result.push_back(matrix[y][x]);
            
            // adjust direction
            if(direction=='d' && x==d_bound){
                direction='s';
                d_bound--;
            }
            if(direction=='s' && y==s_bound){
                direction='a';
                s_bound--;
            }
            if(direction=='a' && x==a_bound){
                direction='w';
                a_bound++;
            }
            if(direction=='w' && y==w_bound){
                direction='d';
                w_bound++;
            }
            // move to next step
            if(direction == 'd'){
                x++;
            }
            else if(direction == 's'){
                y++;
            }
            else if(direction == 'a'){
                x--;
            }
            else{
                y--;
            }
        }
        return result;
    }
};


int main()
{   
    Solution solution;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result = solution.spiralOrder(matrix);
    for(auto m:result){
        cout << m << " ";
    }
    cout << endl;
    return 0;
}
