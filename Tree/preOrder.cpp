/**
 * leetCode#144. Binary Tree Preorder Traversal
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

class Soluiton {
    vector<int> preOrder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sta;
        TreeNode* p = root;
        while(p || !sta.empty())
        {

            if (p != nullptr)
            {
                sta.push(p); /* push stack and save p */
                res.push_back(p->val); /* visit root node */
                p = p->left; /* traverse left */
            }
            else
            {
                p = sta.top();
                sta.pop();
                p = p->right; /* traverse right */
            }
        }
        return res;
    }

};

class Solution2 {
    vector<int> preOrder(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) /* corner case */
            return res;

        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty())
        {
            TreeNode *temp = sta.top();
            res.push_back(temp->val);
            sta.pop();
            if (temp->right != nullptr)
            {
                sta.push(temp->right);
            }
            if (temp->left != nullptr)
            {
                sta.push(temp->left);
            }
        }
        return res;
    }
};

/* recursive */
class Solution3 {
    vector<int> preOrder(TreeNode* root) {
        vector<int> res;
        TreeNode* p = root;
        while(p)
        {
            res.push_back(p->val);
            preOrder(p->left);
            preOrder(p->right);
        }
        return res;
    }
};
