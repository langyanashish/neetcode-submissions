class DSU
{
public:
    vector<int> size, parent;
    int components;
    DSU(int n)
    {
        size.resize(n);
        parent.resize(n);
        components = n;
        for(int i = 0; i < n; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }
    int find(int n)
    {
        if(n != parent[n])
            parent[n] = find(parent[n]);
        return parent[n];
    }
    bool unionBySize(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)
            return false;
        components--;
        if(size[pu] >= size[pv])
        {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else
        {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return true;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto e : edges)
            dsu.unionBySize(e[0], e[1]);
        return dsu.components;
    }
};
