typedef long long ll;

class Solution {
public:
    const int mod = 1e9 + 7;
    static const int N = 100001;
    int fact[N];

    ll binaryexpoiter(ll a, ll b, ll mod) {
        ll ans = 1;
        while (b > 0) {
            if (b & 1)
                ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }

    int countGoodArrays(int n, int m, int k) {
        // Compute factorials
        fact[0] = 1;
        for (int i = 1; i < N; i++) {
            fact[i] = (1LL * i * fact[i - 1]) % mod;
        }

        ll part1 = (1LL * m * fact[n - 1]) % mod;
        ll part2 = binaryexpoiter(fact[n -k- 1], mod - 2, mod);
        ll part3 = binaryexpoiter(fact[k], mod - 2, mod);
        ll part4 = binaryexpoiter(m - 1, n - k - 1, mod);

        ll result = (((part1 * part2) % mod * part3) % mod * part4) % mod;
        return result;
    }
};
