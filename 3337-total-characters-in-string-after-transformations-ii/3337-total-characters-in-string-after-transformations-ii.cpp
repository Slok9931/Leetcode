class Solution {
public:
    long mod = 1e9 + 7;
    void multiplySmall(vector<long long> &grid1, vector<vector<long long>> &grid2){
        vector<long long> curr(26, 0);
        for(int j = 0; j < 26; j++){
            int a = 0;
            for(int k = 0; k < 26; k++){
                a = (a + grid1[k] * grid2[k][j]) % mod;
            }
            curr[j] = a;
        }
        grid1 = curr;
    }
    void multiplyFullMatrix(vector<vector<long long>> &grid1, vector<vector<long long>> &grid2){
        vector<vector<long long>> curr(26, vector<long long>(26, 0));
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                int a = 0;
                for(int k = 0; k < 26; k++){
                    a = (a + grid1[i][k] * grid2[k][j]) % mod;
                }
                curr[i][j] = a;
            }
        }
        grid1 = curr;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<long long>> grid(26, vector<long long>(26,0));
        vector<long long> check(26, 0);
        int n = s.size();
        for(int i = 0; i < 26; i++){
            for(int j = 1; j <= nums[i]; j++){
                grid[i][(i + j) % 26] += 1;
            }
        }
        for(int i = 0; i < n; i++){
            int a = s[i] - 'a';
            check[a] += 1;
        }
        while(t){
            if(t & 1){
                multiplySmall(check, grid);
            }
            t >>=1;
            multiplyFullMatrix(grid, grid);
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans = (ans + check[i])%mod;
        }
        return ans;
    }
};
