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
 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> my_stack;
        TreeNode *cur_node = root;
        while(!my_stack.empty() || cur_node != nullptr){        // 只要my_stack不为空， 或者 root不是nullptr
            if(cur_node != nullptr){
                my_stack.push(cur_node);
                cur_node = cur_node->left;
            }
            else{
                cur_node = my_stack.top();
                my_stack.pop();
                result.push_back(cur_node->val);
                cur_node = cur_node->right;
            }
        }
        return result;
    }

};



int main()
{   
    Solution solution;
    TreeNode *head = new TreeNode(1);                // 二叉树节点


    //  为什么用Binary *head， 而不是Binary head呢，因为Binary_tree的子节点都是指针，使用Binary_tree *head = new Binary_Node(1), 可以保证头节点和子节点的一致性
    head->right = new TreeNode(2);

    head->right->left = new TreeNode(3);

    vector<int> result = solution.inorderTraversal(head);
    for(auto m: result){
        cout << m << " ";
    }

    return 0;
}
