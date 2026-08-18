class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue <int> q;
        int n = candies.size();
        vector <int> vis(n, false), hasBox(n, false), hasKey(n, false);
        int ans = 0;
        for(int i:initialBoxes){
            hasBox[i] = true;
            if(status[i]) q.push(i);
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(vis[x] || !status[x]) continue;
            vis[x] = true;
            ans += candies[x];
            for(int i:containedBoxes[x]){
                hasBox[i] = true;
                if(status[i] && !vis[i]) q.push(i);
            }
            for(int i:keys[x]){
                hasKey[i] = true;
                status[i] = true;
                if(hasKey[i] && hasBox[i] && !vis[i]) q.push(i);
            }
        }
        return ans;
    }
};
