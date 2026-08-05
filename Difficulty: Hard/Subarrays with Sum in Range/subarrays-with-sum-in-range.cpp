class Solution {
private:
    // Helper function to count subarrays with sum <= limit
    long long countSubarraysWithSumAtMost(const std::vector<int>& arr, int limit) {
        if (limit < 0) return 0;

        long long count = 0;
        long long current_sum = 0;
        int left = 0;

        for (int right = 0; right < arr.size(); ++right) {
            current_sum += arr[right];

            // Shrink the window from the left if sum exceeds limit
            while (current_sum > limit && left <= right) {
                current_sum -= arr[left];
                left++;
            }

            // Number of valid subarrays ending at 'right' is window size
            count += (right - left + 1);
        }

        return count;
    }

public:
    int countSubarray(std::vector<int>& arr, int l, int r) {
        return countSubarraysWithSumAtMost(arr, r) - countSubarraysWithSumAtMost(arr, l - 1);
    }
};