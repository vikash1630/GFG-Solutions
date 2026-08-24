class Solution {
private:
    const int MOD = 1000000007;

    // Helper function to calculate (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Helper function to calculate modular inverse (base^(MOD-2) % MOD)
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int prefixStrings(int n) {
        if (n <= 0) return 1;

        // Calculate factorial of (2*n), (n+1), and n modulo 10^9 + 7
        long long num = 1; // (2n)!
        long long den1 = 1; // (n+1)!
        long long den2 = 1; // n!

        for (int i = 1; i <= 2 * n; i++) {
            num = (num * i) % MOD;
            if (i == n + 1) den1 = num; // (n+1)! is the prefix factorial at i = n + 1
            if (i == n) den2 = num;     // n! is the prefix factorial at i = n
        }

        // Formula: C_n = (2n)! * modInverse((n+1)! * n!) % MOD
        long long denominator = (den1 * den2) % MOD;
        long long ans = (num * modInverse(denominator)) % MOD;

        return ans;
    }
};