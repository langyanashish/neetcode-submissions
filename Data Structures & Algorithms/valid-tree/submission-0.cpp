class DSU
{
    public:
    vector<int> parent;
    vector<int> size;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int node)
    {
        if(node != parent[node])
            parent[node] = find(parent[node]);
        return parent[node];
    }
    bool unionBySize(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)
            return false;
        if(size[pu] >= size[pv])
        {
            size[pu] += size[pv];
            parent[pv]= pu;
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
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1)
            return false;
        DSU dsu(n);
        for(auto& e : edges)
        {
            if(!dsu.unionBySize(e[0], e[1]))
                return false;
        }
        for(int s : dsu.size)
            if(s == n)
                return true;
        return false;
    }
};
