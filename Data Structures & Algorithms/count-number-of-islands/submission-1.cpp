class DSU
{
    vector<int> Parent, Size;
public:
    DSU(int n)
    {
        Parent.resize(n+1);
        Size.resize(n+1);
        for(int i = 0; i <= n; i++)
        {
            Parent[i] = i;
            Size[i] = 1;
        }
    }
    int find(int node)
    {
        if(node != Parent[node])
            Parent[node] = find(Parent[node]);
        return Parent[node];
    }

    bool unionBySize(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)
            return false;
        if(Size[pu] >= Size[pv])
        {
            Size[pu] += Size[pv];
            Parent[pv] = pu;
        }
        else
        {
            Size[pv] += Size[pu];
            Parent[pu] = pv;
        }
        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        DSU dsu(m*n);
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        auto index = [&](int r, int c)
        {
            return r * n + c; 
        };
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    for(auto &d : dir)
                    {
                        int nr = i + d[0];
                        int nc = j + d[1];
                        if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == '1')
                        {
                            if(dsu.unionBySize(index(i,j), index(nr, nc)))
                                ans--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
