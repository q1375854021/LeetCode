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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp_result;
        if(root == nullptr){
            return result;
        }
        TreeNode *cur_node = root;
        int cur_sum = root->val;
        temp_result.emplace_back(root->val);
        Process(cur_node, targetSum, cur_sum, temp_result ,result);
        return result;
    }

    void Process(TreeNode *node, int& targetSum, int cur_sum, vector<int> temp_result, vector<vector<int>>& result){
        // add stop condition
        if(cur_sum == targetSum && node->left==nullptr && node->right==nullptr){
            result.emplace_back(temp_result);
        }

        if(node->left != nullptr){
            cur_sum += node->left->val;
            temp_result.emplace_back(node->left->val);
            Process(node->left, targetSum, cur_sum, temp_result, result);
            cur_sum -= node->left->val;
            temp_result.pop_back();
        }
        if(node->right != nullptr){
            cur_sum += node->right->val;
            temp_result.emplace_back(node->right->val);
            Process(node->right, targetSum, cur_sum, temp_result, result);
        }
    }
};



int main()
{   
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
 
    
    vector<vector<int>> result;
    result = solution.pathSum(root, 1);

    for(auto m: result){
        for(auto n: m){
            cout << n << " ";
        }
        cout << endl;
    }
    cout << " test suceess! "<< endl;
    return 0;
}

// test bench 1
// TreeNode *root = new TreeNode(5);
//     root->left = new TreeNode(4);
//     root->left->left = new TreeNode(11);
//     root->left->left->left = new TreeNode(7);
//     root->left->left->right = new TreeNode(2);
//     root->right = new TreeNode(8);
//     root->right->left = new TreeNode(13);
//     root->right->right = new TreeNode(4);
//     root->right->right->left = new TreeNode(5);
//     root->right->right->right = new TreeNode(1);
