class DisJointSet {
public:
    vector<int> parent, size;
    DisJointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0;i<n;i++) {
            parent[i] = i;
        }
    }
    
    int findUlp(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUlp(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int Ulp_u = findUlp(u);
        int Ulp_v = findUlp(v);
        if (Ulp_u == Ulp_v) return;
        if (size[Ulp_v] > size[Ulp_u]) {
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
    int maxRemove(vector<vector<int>>& stones) {
        int maxRows = 0;
        int maxCols = 0;

        for (auto &it : stones) {
            maxRows = max(maxRows, it[0]);
            maxCols = max(maxCols, it[1]);
        }

        // +2 because column nodes start from maxRows + 1
        DisJointSet dis(maxRows + maxCols + 2);

        // Store only the row/column nodes that actually appear
        unordered_map<int, int> nodes;

        for (auto &it : stones) {
            int row = it[0];
            int col = maxRows + it[1] + 1;   // Shift column ids

            dis.unionBySize(row, col);

            // Mark these nodes as used
            nodes[row] = 1;
            nodes[col] = 1;
        }

        int components = 0;

        // Count connected components among only the used nodes
        for (auto &it : nodes) {
            if (dis.findUlp(it.first) == it.first)
                components++;
        }

        // Maximum removable stones
        return stones.size() - components;
    }
};