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
    int ans = 0;
public:
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        dfs(root, ans);
        return ans;
    }
    int dfs(TreeNode* root, int& ans)
    {
        if(!root)
            return 0;
        int lMax = max(dfs(root->left, ans), 0);
        int rMax = max(dfs(root->right, ans), 0);
        ans = max(ans, root->val + lMax + rMax);
        return root->val + max(lMax, rMax);
    }
};
