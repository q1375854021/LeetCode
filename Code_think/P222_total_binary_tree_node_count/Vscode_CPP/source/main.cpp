#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <string>
#include <stack>
#include <queue>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::string;
using std::endl;
using std::stack;
using std::queue;

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
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int count = 1;
        process(root,count);
        return count;
    }

    void process(TreeNode *cur_node, int & cur_index){
        if(cur_node == nullptr){
            return ;
        }
        if(cur_node->right != nullptr ){
            cur_index = cur_index*2+1;
            process(cur_node->right, cur_index);
        }
        else if(cur_node->left != nullptr){
            cur_index = cur_index*2;
            process(cur_node->left, cur_index);
        }
        else{
            return ;
        }
    }
};

int main()
{   
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    
    Solution solution;
    int count = solution.countNodes(root);
    cout << count << endl;
    return 0;
}
