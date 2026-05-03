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
    int pre_idx = 0;
    unordered_map<int, int> indices;

    TreeNode* dfs(vector<int> preorder, int left, int right)
    {
        if(left > right)
            return NULL;
        int val = preorder[pre_idx++];
        TreeNode *root = new TreeNode(val);
        int mid = indices[val];
        root->left = dfs(preorder, left, mid - 1);
        root->right = dfs(preorder, mid + 1, right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            indices[inorder[i]] = i;
        return dfs(preorder, 0, inorder.size() - 1);
    }
};
