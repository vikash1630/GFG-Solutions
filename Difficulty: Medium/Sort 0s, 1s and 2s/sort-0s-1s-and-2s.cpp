class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for (auto &it: arr) {
            if (it == 0) cnt0++;
            else if (it == 1) cnt1++;
            else cnt2++;
        }
        int i = 0;
        while (cnt0 > 0) {
            arr[i] = 0;
            i++;
            cnt0--;
        }
        while (cnt1 > 0) {
            arr[i] = 1;
            cnt1--;
            i++;
        }
        while (cnt2 > 0) {
            arr[i] = 2;
            cnt2--;
            i++;
        }
    }
};