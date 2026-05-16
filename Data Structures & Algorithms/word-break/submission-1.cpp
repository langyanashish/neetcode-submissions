class Solution {
    unordered_set<string> st;
    vector<int> dp;
    bool solve(string& s, int idx)
    {
        if(idx == s.length())
            return true;
        if(dp[idx] != -1)
            return dp[idx];
        string cur = "";
        for(int i = idx; i < s.length(); i++)
        {
            cur += s[i];
            if(st.count(cur) && solve(s, i+1))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word : wordDict)
            st.insert(word);
        dp.resize(s.length(), -1);
        return solve(s, 0);
    }
};
