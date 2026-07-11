class DisjointSet {
  public:
    vector<int> parent, size;
    
    // Constructor
    DisjointSet(int V) {
        parent.resize(V);
        size.resize(V);
        
        for (int i = 0;i<V;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUpar(int node) {
        if (node == parent[node]) return node;
        parent[node] = findUpar(parent[node]);
        return parent[node];
    }
    
    void UnionBySize(int u, int v) {
        int Ulp_u = findUpar(u);
        int Ulp_v = findUpar(v);
        
        if (Ulp_u == Ulp_v) return;
        if (size[Ulp_u] < size[Ulp_v]) {
            size[Ulp_v] += size[Ulp_u];
            parent[Ulp_u] = Ulp_v;
        }
        else {
            size[Ulp_u] += size[Ulp_v];
            parent[Ulp_v] = Ulp_u;
        }
    }
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        int n = edges.size();
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });
        DisjointSet dis(V);
        int ans = 0;
        for (int i = 0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            if (dis.findUpar(u) != dis.findUpar(v)) {
                dis.UnionBySize(u, v);
                ans += wt;
            }
        }
        return ans;
    }
};