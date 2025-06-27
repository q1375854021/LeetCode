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
    int uniquePaths(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // define dp array 
        vector<vector<int>> dp(m, vector(n,0));
        // set the primary status
        for(int j=0; j<m; j++){
            if(obstacleGrid[j][0]==1){
                break;
            }
            dp[j][0] = 1;
        }
        for(int i=0; i<n; ++i){
            if(obstacleGrid[0][i]==1){
                break;
            }
            dp[0][i] = 1;
        }
        // begin dynamic programming
        for(int j=1; j<m; j++){
            for(int i=1; i<n; ++i){
                if(obstacleGrid[j][i]==0){
                    dp[j][i] = dp[j-1][i] + dp[j][i-1];
                }
                else{
                    dp[j][i]=0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};


int main()
{   
    Solution solution;
    int result = solution.uniquePaths(3,7);
    cout << result << endl;
    return 0;
}
