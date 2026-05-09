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

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
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
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if(cur->childs[idx] == NULL)
                return false;
            cur = cur->childs[idx];
        }
        return cur->isWordEndsHere;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            int idx = prefix[i] - 'a';
            if(cur->childs[idx] == NULL)
                return false;
            cur = cur->childs[idx];
        }
        return true;        
    }
};
