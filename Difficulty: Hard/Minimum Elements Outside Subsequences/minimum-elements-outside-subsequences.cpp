class Solution {
private:
    int solve(vector<int>& arr, int ind, int incLast, int decLast, int n,
              vector<vector<vector<int>>>& dp) {

        if (ind == n)
            return 0;

        if (dp[ind][incLast + 1][decLast + 1] != -1)
            return dp[ind][incLast + 1][decLast + 1];

        // Don't take this element
        int dontTake = solve(arr, ind + 1, incLast, decLast, n, dp);

        int takeInc = 0;
        int takeDec = 0;

        // Put current element in increasing subsequence
        if (incLast == -1 || arr[ind] > arr[incLast]) {
            takeInc = 1 + solve(arr, ind + 1, ind, decLast, n, dp);
        }

        // Put current element in decreasing subsequence
        if (decLast == -1 || arr[ind] < arr[decLast]) {
            takeDec = 1 + solve(arr, ind + 1, incLast, ind, n, dp);
        }

        return dp[ind][incLast + 1][decLast + 1] =
            max({dontTake, takeInc, takeDec});
    }

public:
    int minCount(vector<int>& arr) {
        int n = arr.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n + 1,
            vector<int>(n + 1, -1))
        );

        int maxSelected = solve(arr, 0, -1, -1, n, dp);

        return n - maxSelected;
    }
};