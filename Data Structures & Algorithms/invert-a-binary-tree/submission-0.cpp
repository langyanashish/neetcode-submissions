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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        if(!root->left && !root->right)
            return root;
        swap(root->left, root->right);
        TreeNode* leftSubtree = invertTree(root->left);
        TreeNode* rightSubtree = invertTree(root->right);
        return new TreeNode(root->val, leftSubtree, rightSubtree);;
    }
};
/*
    4       4
   2  7     7  2
  1 3 6 9  9 6 3 1

*/
