class Solution {
public:
    int mod = 1000000000 + 7;
    unordered_map<int,int> dp;

    int Sol(int n) {
        if(n <= 0 ) {
            return 1;
        }
        if(dp.count(n) != 0) {
            return dp[n];
        }
        int ans = (Sol(n-26) + Sol(n-25)) % mod;
        dp[n] = ans;
        return ans;
    }
    int lengthAfterTransformations(string s, int t) {
        int length = 0;

        for(const auto& c : s) {
            length = (length + Sol(t - ('z' - c))) % mod;
        }

        return length;
    }
};
