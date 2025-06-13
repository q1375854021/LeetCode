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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<int> to_reverse;
        stack<TreeNode *> my_stack;
        if(root == nullptr){
            return result;
        }
        TreeNode *cur_node = root;
        my_stack.push(cur_node);
        while(!my_stack.empty()){
            cur_node = my_stack.top();
            to_reverse.push(cur_node->val);
            my_stack.pop();

            if(cur_node->left != nullptr){
                my_stack.push(cur_node->left);
            }
            if(cur_node->right != nullptr){
                my_stack.push(cur_node->right);
            }
        }
        while(!to_reverse.empty()){
            result.push_back(to_reverse.top());
            to_reverse.pop();
        }
        return result;
    }
};


int main()
{   
    Solution solution;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(4);
    head->left->left->left = new TreeNode(6);
    head->left->left->right = new TreeNode(7);
    head->left->right = new TreeNode(5);
    head->left->right->right = new TreeNode(8);
    head->right = new TreeNode(3);
    head->right->left = new TreeNode(9);
    head->right->right = new TreeNode(10);
    head->right->right->right = new TreeNode(11);
    vector<int> result = solution.postorderTraversal(head);
    for(auto m : result){
        cout << m << " ";
    }
    return 0;
}
