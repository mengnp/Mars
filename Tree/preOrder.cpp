/**
 * leetCode#144. Binary Tree Preorder Traversal
 *
 * Struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 */

#include <vector>
using namespace std;

class Soluiton {
    vector<int> preOrder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sta;
        TreeNode* p = root;
        while(p || !sta.empty())
        {

            if (p != NULL)
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
        if (root == NULL) /* corner case */
            return res;

        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty())
        {
            TreeNode *temp = sta.top();
            res.push_back(temp->val);
            sta.pop();
            if (temp->right != NULL)
            {
                sta.push(temp->right);
            }
            if (temp->left != NULL)
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
