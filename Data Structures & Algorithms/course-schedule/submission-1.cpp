class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites)
        {
            int u = p[0];
            int v = p[1];
            inDegree[u]++;
            adj[v].push_back(u);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }
        int done = 0;
        while(!q.empty())
        {
            done++;
            auto cur = q.front();
            q.pop();
            for(int nei : adj[cur])
            {
                inDegree[nei]--;
                if(inDegree[nei] == 0)
                    q.push(nei);
            }
        }
        return done == numCourses;
    }
};
