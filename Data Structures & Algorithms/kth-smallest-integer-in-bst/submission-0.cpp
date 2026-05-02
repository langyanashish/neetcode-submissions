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
    int count, ans;
public:
    void inorderTraversal(TreeNode* root, int k)
    {
        if(!root)
            return;
        inorderTraversal(root->left, k);
        count++;
        if(count == k)
        {
            ans = root->val;
            return;
        }
        inorderTraversal(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        inorderTraversal(root, k);
        return ans;
    }
};
