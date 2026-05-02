class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int repeating = -1, missing = -1;

        for (int i = 1; i < n; i++) {
            // repeating
            if (arr[i] == arr[i - 1]) {
                repeating = arr[i];
            }
            // missing
            else if (arr[i] > arr[i - 1] + 1) {
                missing = arr[i - 1] + 1;
            }
        }

        // edge cases
        if (arr[0] != 1) {
            missing = 1;
        }
        if (arr[n - 1] != n) {
            missing = n;
        }

        return {repeating, missing};
    }
};