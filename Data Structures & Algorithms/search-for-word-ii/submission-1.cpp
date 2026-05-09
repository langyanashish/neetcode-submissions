class Solution {
    bool found = false;
    void solve(vector<vector<char>>& board, string word, int i, int j, int idx, vector<vector<bool>>& visited)
    {
        if(idx == word.size())
        {
            found = true;
            return;
        }
        if(i < 0 || j < 0 || i >= board.size() || j > board[0].size())
            return;
        if(visited[i][j])
            return;
        if(board[i][j] == word[idx])
        {
            visited[i][j] = true;
            solve(board, word, i+1, j, idx+1, visited);
            solve(board, word, i, j+1, idx+1, visited);
            solve(board, word, i-1, j, idx+1, visited);
            solve(board, word, i, j-1, idx+1, visited);
            visited[i][j] = false;
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
        vector<string> res;
        for(auto word: words)
        {
            found = false;
            for(int i = 0; i < board.size(); i++)
            {
                for(int j = 0; j < board[0].size(); j++)
                {
                    if(board[i][j] == word[0])
                    {
                        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                        solve(board, word, i, j, 0, visited);
                    }
                }
            }
            if(found)
                res.push_back(word);
        }
        return res;
    }
};
