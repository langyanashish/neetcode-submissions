class TrieNode {
public:
    TrieNode* childs[26];
    int idx;
    int refs;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            childs[i] = nullptr;
        }
        idx = -1;
        refs = 0;
    }

    void addWord(const string& word, int i) {
        TrieNode* cur = this;
        cur->refs++;
        for (char c : word) {
            int index = c - 'a';
            if (!cur->childs[index]) {
                cur->childs[index] = new TrieNode();
            }
            cur = cur->childs[index];
            cur->refs++;
        }
        cur->idx = i;
    }
};

class Solution {
    vector<string> res;
    void dfs(auto& board, TrieNode* node, int r, int c, auto& words)
    {
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '*' || !node->childs[board[r][c]- 'a'])
            return;

        char temp = board[r][c];
        board[r][c] = '*';
        TrieNode* prev = node;
        node = node->childs[temp-'a'];
        if(node->idx != -1)
        {
            res.push_back(words[node->idx]);
            node->idx = -1;
            node->refs--;
            if(!node->refs)
            {
                prev->childs[temp-'a'] = NULL;
                node = NULL;
                board[r][c] = temp;
                return;
            }
        }
        dfs(board, node, r+1, c, words);
        dfs(board, node, r, c+1, words);
        dfs(board, node, r-1, c, words);
        dfs(board, node, r, c-1, words);
        board[r][c] = temp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
        TrieNode* root = new TrieNode();
        for(int i = 0; i < words.size(); i++)
            root->addWord(words[i], i);
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                dfs(board, root, i, j, words);
        return res;
    }
};
