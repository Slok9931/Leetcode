class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;
        vector<long long> cnt(mx + 1, 0);
        vector<int> multipleCnt(mx + 1, 0);
        for (int g = 1; g <= mx; g++) {
            for (int j = g; j <= mx; j += g)
                multipleCnt[g] += freq[j];
        }
        for (int g = mx; g >= 1; g--) {
            long long c = multipleCnt[g];
            cnt[g] = c * (c - 1) / 2;
            for (int j = 2 * g; j <= mx; j += g)
                cnt[g] -= cnt[j];
        }
        vector<long long> pref;
        vector<int> gcdVal;
        long long sum = 0;
        for (int g = 1; g <= mx; g++) {
            if (cnt[g] > 0) {
                sum += cnt[g];
                pref.push_back(sum);
                gcdVal.push_back(g);
            }
        }
        vector<int> ans;
        for (long long q : queries) {
            int idx = lower_bound(pref.begin(), pref.end(), q + 1) - pref.begin();
            ans.push_back(gcdVal[idx]);
        }
        return ans;
    }
};
