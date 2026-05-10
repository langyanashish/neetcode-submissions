class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;
        for(string w : words)
        {
            for(char c : w)
            {
                adj[c] = unordered_set<char>();
                inDegree[c] = 0;
            }
        }
        for(int i = 0; i < words.size()-1; i++)
        {
            string u = words[i], v = words[i+1];
            int minLen = min(u.length(), v.length());
            if(u.length() > v.length() && u.substr(0, minLen) == v.substr(0, minLen))
                return ""; //order invalid
            for(int j = 0; j < minLen; j++)
            {
                if(u[j] != v[j])
                {
                    if(!adj[u[j]].count(v[j]))
                    {
                        adj[u[j]].insert(v[j]);
                        inDegree[v[j]]++;
                    }
                    break;
                }
            }
        }
        queue<char>q;
        for(auto &[c, deg] : inDegree)
        {
            if(deg == 0)
                q.push(c);
        }
        string ans;
        while(!q.empty())
        {
            char cur = q.front();
            q.pop();
            ans += cur;
            for(auto nei : adj[cur])
            {
                inDegree[nei]--;
                if(inDegree[nei] == 0)
                    q.push(nei);
            }
        }
        return ans.size() == inDegree.size() ? ans : "";
    }
};
