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
    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }
    bool isValid(TreeNode* root, TreeNode* leftParent, TreeNode* rightParent)
    {
        if(!root)
            return true;
        if(leftParent && root->val <= leftParent->val)
            return false;
        if(rightParent && root->val >= rightParent->val)
            return false;
        return isValid(root->left, leftParent, root) && isValid(root->right, root, rightParent);
    }
};
