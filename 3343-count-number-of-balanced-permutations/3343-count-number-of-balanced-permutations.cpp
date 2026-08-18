#define ll long long
class Solution {
public:
    int md = 1e9 + 7;
    int countBalancedPermutations(string num) {
        int n = num.size();
        ll sm = 0;
        for(int i=0;i<n;i++){
            sm += (num[i] - '0');
        }
        if(sm%2) return 0;

        vector<ll> fact(n+1,1);
        for(int i=1;i<=n;i++){
            fact[i] = (fact[i-1]*i)%md;
        }
        vector<ll> inv(n+1,1);
        for(int i=2;i<=n;i++){
            inv[i] = md - (md/i)*inv[md%i] %md;
        }
        vector<ll> infact(n+1,1);
        for(int i=1;i<=n;i++){
            infact[i] = (infact[i-1]*inv[i])%md;
        }
        vector<ll> dig(10);
        vector<vector<ll>> dp(sm/2 +1 ,vector<ll>(n/2 + 1, 0));
        dp[0][0] = 1;
        for(int i=0;i<n;i++){
            int d = num[i] - '0';
            dig[d]++;
            for(int j=sm/2;j>=d;j--){
                for(int k=n/2;k>0;k--){
                    dp[j][k] = (dp[j][k] + dp[j-d][k-1])%md;
                }
            }
        }
        ll ans = (((dp[sm/2][n/2] * fact[n/2])%md) * (fact[n - n/2]))%md;
        for(int i=0;i<10;i++){
            ans = (ans * infact[dig[i]])%md;
        }
        return ans;
    }
};
