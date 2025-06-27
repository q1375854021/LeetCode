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




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 首先我要得到每一条路径的和， 然后判断是否等于target_Sum  有一条等于我就可以直接返回
        if(root==nullptr){
            return false;
        }
        int sum = 0;
        bool flag = false;
        process(root, sum, flag, targetSum);
        return flag;
        
    }

    
    void process(TreeNode *cur_node, int &sum, bool& flag, int targetsum){
        if(cur_node->left==nullptr && cur_node->right==nullptr){
            sum += cur_node->val;
            if(sum == targetsum) flag = true;
            sum -= cur_node->val;
            return ;
        }
        sum += cur_node->val;
        if(cur_node->left != nullptr){
            process(cur_node->left, sum, flag, targetsum);
        }
        if(cur_node->right != nullptr){
            process(cur_node->right, sum, flag, targetsum);
        }
        sum -= cur_node->val;
    }


};

int main()
{   
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    bool result = solution.hasPathSum(root, 1);
    cout << result << endl;
    cout << " test suceess! "<< endl;
    return 0;
}
