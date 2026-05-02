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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q, tq;
        q.push(root);
        ans.push_back({root->val});
            vector<int> temp;
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left)
            {
                temp.push_back(cur->left->val);
                tq.push(cur->left);
            }
            if(cur->right)
            {
                temp.push_back(cur->right->val);
                tq.push(cur->right);
            }
            if(q.empty() && !tq.empty())
            {
                while(!tq.empty())
                {
                    q.push(tq.front());
                    tq.pop();
                }
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};
