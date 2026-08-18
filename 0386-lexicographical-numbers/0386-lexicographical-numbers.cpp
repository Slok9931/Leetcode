class Solution {
public:
    void dfs(int i, int n, vector<int> & ans){
        if(i > n) return;
        ans.push_back(i);
        for(int j=0;j<10;j++){
            int x = 10*i + j;
            if(x > n) return;
            dfs(x, n, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector <int> ans;
        for(int i=1;i<10;i++) dfs(i, n, ans);
        return ans;
    }
};
