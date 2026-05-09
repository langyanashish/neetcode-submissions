struct TrieNode
{
    TrieNode* childs[26];
    bool isWordEndsHere;

    TrieNode()
    {
        for(int i = 0; i < 26; i++)
            childs[i] = NULL;
        isWordEndsHere = false;
    }
};

class WordDictionary {
    TrieNode* root;
    bool dfs(string word, int idx, TrieNode* root)
    {
        TrieNode* cur = root;
        for(int i = idx; i < word.size(); i++)
        {
            char c = word[i];
            if(c == '.')
            {
                for(auto child : cur->childs)
                {
                    if(child != NULL && dfs(word, i+1, child))
                        return true;
                }
                return false;
            }
            else
            {
                if(cur->childs[c-'a'] == NULL)
                    return false;
                cur = cur->childs[c-'a'];
            }
        }
        return cur->isWordEndsHere;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if(cur->childs[idx] == NULL)
                cur->childs[idx] = new TrieNode();
            cur = cur->childs[idx];
        }
        cur->isWordEndsHere = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
