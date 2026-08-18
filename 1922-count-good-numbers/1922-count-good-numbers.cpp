class Solution {
public:
    const int MOD = 1e9 + 7;

    // Modular exponentiation function
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_positions = n / 2;
        long long odd_positions = n - even_positions;

        long long odd_pow = power(5, odd_positions, MOD);
        long long even_pow = power(4, even_positions, MOD);

        return (odd_pow * even_pow) % MOD;
    }
};
