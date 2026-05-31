class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
        // Key Fact
        // A positive integer can be written as a sum of two or 
        // more consecutive positive integers iff it is NOT a power of 2.
        return (n & (n - 1)) != 0;
    }
};