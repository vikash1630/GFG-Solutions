class Solution {
	private:
	// int solve(vector<int> &arr, int i, int j) {
	//     if (i == j) return 0;
	//     int mini = 1e8;
	//     for (int k = i;k<j;k++) {
	//         int sum = arr[i - 1] * arr[k] * arr[j] + solve(arr, i, k) + solve(arr, k + 1, j);
	//         mini = min(sum, mini);
	//     }
	//     return mini;
	// }
	
	int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
		if (i == j)
			return 0;
		
		// If already computed, return from dp
		if (dp[i][j] != -1)
			return dp[i][j];
		
		// Initialize min cost as very large
		int minCost = INT_MAX;
		
		// Try every partition
		for (int k = i; k < j; k++) {
			int cost1 = solve(arr, i, k, dp);
			int cost2 = solve(arr, k + 1, j, dp);
			int costMultiply = arr[i - 1] * arr[k] * arr[j];
			
			int total = cost1 + cost2 + costMultiply;
			
			minCost = min(minCost, total);
		}
		
		return dp[i][j] = minCost;
	}
	
	public:
	int matrixMultiplication(vector<int> &arr) {
		// code here
		int n = arr.size();
		vector<vector<int>> dp(n, vector<int>(n, -1));
		return solve(arr, 1, n - 1, dp);
	}
};
