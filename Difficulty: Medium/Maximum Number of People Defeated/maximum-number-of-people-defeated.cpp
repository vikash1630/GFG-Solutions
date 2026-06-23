class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        if (p == 0) return 0;
        if (p == 1) return 1;
        int i = 1;
        int defeated = 0;
        while (p >= 0) {
            p -= i * i;
            if (p >= 0) defeated++;
            i++;
        }
        return defeated;
    }
};
