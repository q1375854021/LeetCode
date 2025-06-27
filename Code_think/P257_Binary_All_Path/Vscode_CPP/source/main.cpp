#include <iostream>
#include <regex>
#include <vector>
#include <numeric>
#include <list>
#include <string>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> temp_result;
        if(root==nullptr){
            return result;
        }
        process(root, result, temp_result);
        return result;
    }

    void process(TreeNode *cur_node, vector<string> &result, vector<int> &temp_result){
        if(cur_node == nullptr){
            return ;
        }
        // 把最后一个点加到path中
        temp_result.push_back(cur_node->val);
        if(cur_node->left == nullptr && cur_node->right==nullptr){
            string str;
            int size = temp_result.size();
            for(int i=0; i<size-1; ++i){
                str += to_string(temp_result[i]);
                str += '-';
                str += '>';
            }
            str += to_string(temp_result[size-1]);
            result.push_back(str);
            return ;
        }
        if(cur_node->left != nullptr){
            process(cur_node->left, result, temp_result);
            temp_result.pop_back();
        }
        if(cur_node->right != nullptr){
            process(cur_node->right, result, temp_result);
            temp_result.pop_back();
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
    vector<string> result = solution.binaryTreePaths(root);
    for(auto m: result){
        cout << m << endl;
    }
    return 0;
}
