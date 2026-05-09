class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, set<int>> mp;
        for(auto p : prerequisites)
        {
            inDegree[p[1]]++;
            mp[p[0]].insert(p[1]);
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
            for(int nei : mp[cur])
            {
                inDegree[nei]--;
                if(inDegree[nei] == 0)
                    q.push(nei);
            }
        }
        return done == numCourses;
    }
};
