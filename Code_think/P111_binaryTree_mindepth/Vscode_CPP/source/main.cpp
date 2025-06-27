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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if (nullptr == root) {
            return res;
        }

        std::stack<TreeNode*> myStack;
        while ((nullptr != root) || (!myStack.empty())) {
            while (nullptr != root) {
                res.push_back(root->val);
                myStack.push(root);
                root = root->left;
            }
            root = myStack.top();
            myStack.pop();
            if (nullptr != root->right) {
                root = root->right;
                continue;
            }
            root = nullptr;
        }
        return res;
    }
};

int main()
{   
    Solution solution;
    string str("abbacd");
    str = solution.removeDuplicates(str);
    cout << str << endl;
    return 0;
}
