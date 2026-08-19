class Solution {
private:
    long long countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        long long count = 0;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = 1LL * arr[i] + arr[left] + arr[right];

                if (sum <= x) {
                    // Every element from left+1 ... right
                    // can form a valid triplet with i and left.
                    count += right - left;
                    left++;
                } 
                else {
                    right--;
                }
            }
        }

        return count;
    }

public:
    int countTriplets(vector<int>& arr, int l, int r) {
        sort(arr.begin(), arr.end());

        return countLessEqual(arr, r) - countLessEqual(arr, l - 1);
    }
};