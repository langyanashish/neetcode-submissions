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

class Codec {
    void dfsSerialize(TreeNode* root, vector<string>& ans)
    {
        if(!root)
        {
            ans.push_back("N");
            return;
        }
        ans.push_back(to_string(root->val));
        dfsSerialize(root->left, ans);
        dfsSerialize(root->right, ans);
    }
    TreeNode* dfsDeserialize(vector<string> val, int& i)
    {
        if(val[i] == "N")
        {
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(val[i]));
        i++;
        node->left = dfsDeserialize(val, i);
        node->right = dfsDeserialize(val, i);
        return node;
    }
    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    string join(const vector<string> &v, const string &delim) {
        ostringstream s;
        for (const auto &i : v) {
            if (&i != &v[0])
                s << delim;
            s << i;
        }
        return s.str();
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> ans;
        dfsSerialize(root, ans);
        return join(ans, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> val = split(data, ',');
        int i = 0;
        return dfsDeserialize(val, i);
    }
};
