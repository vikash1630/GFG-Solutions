class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int n = height.size();
        if (n <= 2) return 0;
        int left = 0;
        int right = n - 1;
        int dis = n - 2;
        int ans = INT_MIN;
        while (left < right) {
            int a = height[left];
            int b = height[right];
            int area = min(a,b) * dis;
            ans = max(ans,area);
            if (a > b) {
                right--;
            }
            else left++;
            dis--;
        }
        return ans;
    }
};