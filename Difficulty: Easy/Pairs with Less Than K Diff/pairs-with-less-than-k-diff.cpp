class Solution {
public:
    int countPairs(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            int idx = lower_bound(arr.begin() + i + 1, arr.end(), arr[i] + k) - arr.begin();

            // Elements from i+1 to idx-1 satisfy arr[j] - arr[i] < k
            ans += (idx - i - 1);
        }

        return ans;
    }
};