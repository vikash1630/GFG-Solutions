class Solution {
  private:
    bool isSafe(int color,vector<int> &colors, vector<vector<int>> &adjL, int node) {
        for (auto &it: adjL[node]) {
            if (colors[it] == color) return false;
        }
        return true;
    }
    
    bool coloring(int node, int V, vector<int> &colors, vector<vector<int>> &adjL, int m) {
        if (node == V) return true;
        for (int color = 1;color<=m;color++) {
            if (isSafe(color, colors, adjL, node)) {
                colors[node] = color;
                // Explore
                if (coloring(node + 1, V, colors, adjL, m)) {
                    return true;
                }
                colors[node] = 0;
            }
        }
        return false;
    }
    
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adjL(v);
        for(auto &it: edges) {
            int u = it[0];
            int V = it[1];
            adjL[u].push_back(V);
            adjL[V].push_back(u);
        }
        vector<int> colors(v + 1, 0);
        return coloring(0, v, colors, adjL, m);
        
    }
};