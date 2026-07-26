class Solution {
public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        int n = arr.size();
        int levels = floor(log2(n)) + 1;

        vector<vector<int>> ans(levels);

        priority_queue<int, vector<int>, greater<int>> pq;

        int it = 0;

        // First level
        pq.push(arr[it++]);

        int level = 0;

        while (!pq.empty()) {

            int curSize = pq.size();

            // Store current level in sorted order
            for (int i = 0; i < curSize; i++) {
                ans[level].push_back(pq.top());
                pq.pop();
            }

            // Push next level nodes
            int nextSize = min(2 * curSize, n - it);

            for (int i = 0; i < nextSize; i++) {
                pq.push(arr[it++]);
            }

            level++;
        }

        return ans;
    }
};