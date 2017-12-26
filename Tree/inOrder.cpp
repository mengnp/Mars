/**
 * leetCode#94. Binary Tree Inorder Traversal
 */
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    vector<int> inOrder(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> sta;
        TreeNode *p = root;

        /* p is not null or sta is not empty */
        while (p || !sta.empty()){
            if (p != nullptr)
            {
                sta.push(p);
                p = p->left; /* find the last left */
            }
            else
            {
                p = sta.top();
                sta.pop();
                res.push_back(p->val); /* visit root node */
                p = p->right;
            }
        }
        return res;
    }

};

/* recursive */
class Solution2 {
    vector<int> inOrder(TreeNode* root){
        vector<int> res;
        TreeNode* p = root;

        while(p)
        {
            inOrder(p->left);
            res.push_back(p->val);
            inOrder(p->right);
        }
        return res;
    }
};
