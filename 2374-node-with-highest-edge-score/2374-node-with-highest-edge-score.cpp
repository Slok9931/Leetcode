class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n, 0);
        for(int i=0;i<n;i++) score[edges[i]] += i;
        int ans = n;
        long long maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(score[i] > maxi){
                ans = i;
                maxi = score[i];
            }
            else if(score[i] == maxi) ans = min(ans, i);
        }
        return ans;
    }
};
