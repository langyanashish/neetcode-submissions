class Solution {    
    bool toPacific(auto& matrix, int r, int c)
    {
        if(r == 0 || c == 0)
            return true;
        if(mp.count({r,c}))
            return mp[{r,c}];
        if(vp.count({r,c}))
            return false;
        vp.insert({r,c});
        int dir[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0,-1}};
        for(auto& d : dir)
        {
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr >= 0 && nc >= 0 &&
                nr < matrix.size() && nc < matrix[0].size() &&
                matrix[nr][nc] <= matrix[r][c] && toPacific(matrix, nr, nc))
            {
                vp.erase({r,c});
                return mp[{r, c}] = true;
            }
        }
        vp.erase({r,c});
        return mp[{r, c}] = false;
    }
    bool toAtlantic(auto& matrix, int r, int c)
    {
        int m = matrix.size(), n = matrix[0].size();
        if(r == m-1 || c == n-1)
            return true;
        if(ma.count({r,c}))
            return ma[{r,c}];
        if(va.count({r,c}))
            return false;
        va.insert({r,c});
        int dir[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0,-1}};
        for(auto& d : dir)
        {
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr >= 0 && nc >= 0 &&
                nr < matrix.size() && nc < matrix[0].size() &&
                matrix[nr][nc] <= matrix[r][c] && toAtlantic(matrix, nr, nc))
            {
                va.erase({r,c});
                return ma[{r, c}] = true;
            }
        }
        va.erase({r,c});
        return ma[{r, c}] = false;
    }
public:
    map <pair<int, int>, int> mp, ma;
    set <pair<int, int>> vp, va;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(toPacific(v, i, j) && toAtlantic(v, i, j))
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
