/**
 * leetCode#145. Binary Tree Postorder Traversal
 * Solution: use two stacks.
 * 1. Push the root node to the first stack
 * 2. Pop a node from the first stack, and push it to the second stack
 * 3. Push its left child followed by its right child to the first stack
 * 4. Repeat step 2) and 3) until the first stack is empty
 * 5. Pop off the nodes from the second stack
 */

#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};


class Solution {
    vector<int> postOrder(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        vector<int> res;
        if (root == nullptr) /* corner case */
            return res;

        TreeNode *curr;
        s1.push(root);

        while(!s1.empty()){
            curr = s1.top();
            s1.pop();
            s2.push(curr);
            if (curr->left)
                s1.push(curr->left);
            if (curr->right)
                s1.push(curr->right);
        }
        while(!s2.empty()){
            res.push_back(s2.top()->val);
            s2.pop();
        }
        return res;
    }
};
