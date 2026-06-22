class Solution {
public:
    int numberOfSubarrays(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int num : arr) {
            sum += num;

            if (mp.find(sum - target) != mp.end()) {
                count += mp[sum - target];
            }

            mp[sum]++;
        }

        return count;
    }
};