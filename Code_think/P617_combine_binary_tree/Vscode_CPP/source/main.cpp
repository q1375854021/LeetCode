#include <cstddef>
#include <iostream>
#include <unordered_map>
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
using std::find;
using std::unordered_map;


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
    // 根据中序遍历和后序遍历构建二叉树
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0){
            return nullptr;
        }
        TreeNode *root = tranversal(inorder, postorder);
        return root;
    }
    TreeNode *tranversal(vector<int> inorder, vector<int> postorder){
        if(postorder.size()==0){
            return nullptr;
        }
        // 找到头节点
        int root_val = postorder[postorder.size()-1];
        TreeNode *cur_root = new TreeNode(root_val);
        if(postorder.size()==1){
            return cur_root;
        }
        // 找到头节点，那么开始在中序遍历中找到分割点
        int index = 0;
        for(int i=0; i<inorder.size();++i){
            if(inorder[i]==root_val){
                index = i;
                break;
            }
        }

        // 在后序遍历结果中删掉最后一个
        postorder.resize(postorder.size()-1);

        // 开始分割中序节点   左闭右开
        vector<int> left_inorder(inorder.begin(), inorder.begin()+index);
        vector<int> right_inorder(inorder.begin()+index+1, inorder.end());

        // 然后开始分割后续遍历  左闭右开
        vector<int> left_postorder(postorder.begin(), postorder.begin()+index);
        vector<int> right_postorder(postorder.begin()+index, postorder.end());

        cur_root->left = tranversal(left_inorder, left_postorder);
        cur_root->right = tranversal(right_inorder, right_postorder);
        return cur_root;
    }

    // 中序遍历
    void inorder(TreeNode *root){
        if(root == nullptr){
            return ;
        }
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    // 后序遍历
    void postorder(TreeNode *root){
        if(root == nullptr){
            return ;
        }
        inorder(root->left);
        inorder(root->right);
        cout << root->val << " ";
    }

    // 合并二叉树
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        process(&root1, &root2);
        return root1;
    }

    // 迭代
    void process(TreeNode **root1, TreeNode **root2){
        if((*root1)==nullptr && (*root2)==nullptr){
            cout << "run cond 1 \n";
            return ;
        }
        else if((*root1)==nullptr && (*root2) != nullptr){
            cout << "run cond 2 \n";
            *root1 = new TreeNode(0);
        }
        else if((*root2)==nullptr && (*root1)!=nullptr){
            cout << "run cond 3 \n";
            *root2 = new TreeNode(0);
        }
        else{
            cout << "run cond 4 \n";
        }
        (*root1)->val += (*root2)->val;
        process(&((*root1)->left), &((*root2)->left));
        process(&((*root1)->right), &((*root2)->right));
    }
};

int main()
{   
    Solution solution;
    vector<int> inorder_vec{3,2,1};
    vector<int> postorder_vec{3,2,1};
    TreeNode *root1 = solution.buildTree(inorder_vec, postorder_vec);
    inorder_vec = {};
    postorder_vec = {};
    inorder_vec = {1,2,3};
    postorder_vec = {3,2,1};
    TreeNode *root2 = solution.buildTree(inorder_vec, postorder_vec);
    TreeNode *root = solution.mergeTrees(root1, root2);
    solution.inorder(root);
    cout << endl;
    solution.postorder(root);
    return 0;
}
