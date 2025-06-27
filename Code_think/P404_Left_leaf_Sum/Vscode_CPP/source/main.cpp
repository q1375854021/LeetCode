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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // 首先先找到一样值的结点
        vector<TreeNode *> head;
        FindHead(root, subRoot, head);
        // 然后以该节点为头节点，判断两棵树是否一致
        bool result = false;
        for(auto m: head){
            result = isSameTree(m, subRoot);
            if(result) return true;
        }
        return false;
        
    }

    void FindHead(TreeNode* root, TreeNode* subRoot, vector<TreeNode*>& head){
        if(root ==nullptr){
            return ;
        }
        if(root->val == subRoot->val){
            head.push_back(root);
        }
        FindHead(root->left, subRoot, head);
        FindHead(root->right, subRoot, head);
    }

    bool isSameTree(TreeNode *root1, TreeNode *root2){
        if(root1==nullptr && root2==nullptr){
            return true;
        }
        else if( (root1==nullptr && root2!=nullptr) || (root1!=nullptr && root2==nullptr)){
            return false;
        }
        else{
            if(root1->val != root2->val){
                return false;
            }
            return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
        }
    }
};

int main()
{   
    Solution solution;
    TreeNode *root1 = new TreeNode(1);
    root1->right = new TreeNode(1);
    root1->right->right = new TreeNode(1);
    root1->right->right->right = new TreeNode(1);
    root1->right->right->right->left = new TreeNode(2);


    TreeNode *root2 = new TreeNode(1);
    root2->right = new TreeNode(1);
    root2->right->right = new TreeNode(1);
    root2->right->right->left = new TreeNode(2);

    cout << solution.isSubtree(root1, root2);
    return 0;
}
