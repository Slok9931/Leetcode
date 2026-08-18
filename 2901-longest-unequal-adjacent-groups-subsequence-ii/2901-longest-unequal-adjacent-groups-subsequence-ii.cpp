class Solution {
public:
    int dp[1000][1001];
    int path[1000][1001];
    vector<string>ans;
    void findPath(vector<string>& words, vector<int>& groups, int i,int j){
        if(i>=words.size()) return;
        if(path[i][j+1]==1){
            ans.push_back(words[i]);
            findPath(words,groups,i+1,i);
            return;
        }
        findPath(words,groups,i+1,j);
        return;
    }
    int solve(vector<string>& words, vector<int>& groups, int i, int j){
        if(i>=words.size()) return 0;
        if(dp[i][j+1]!=-1 ) return dp[i][j+1];
        if(j==-1){
            int take = 1+solve(words,groups,i+1,i);
            int notTake = solve(words,groups,i+1,j);
            if(take>notTake) path[i][j+1] = 1;
            else path[i][j+1] = 0;
            return dp[i][j+1] = max(take,notTake);
        }
        if(groups[i]==groups[j]){
            path[i][j+1]=0;
            return dp[i][j+1]=solve(words,groups,i+1,j);
        }
        if(words[i].size()!=words[j].size()){ 
            path[i][j+1] = 0;
            return dp[i][j+1] = solve(words,groups,i+1,j);
        }
        int hamming = 0;
        for(int x=0;x<words[i].size();x++) if(words[i][x]!=words[j][x]) hamming++;
        if(hamming!=1) {
            path[i][j+1]=0;
            return dp[i][j+1] = solve(words,groups,i+1,j);
        }
        int take = 1+solve(words,groups,i+1,i);
        int notTake = solve(words,groups,i+1,j);
        if(take>notTake) path[i][j+1]=1;
        else path[i][j+1]=0;
        return dp[i][j+1] = max(take,notTake);
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // lets try it...
        // revise this question later.... important question
        // if you want to track the path of the lis...
        //-------> just make sure you carry a path matrix with you if take>notTake update path matrix to 1 as you are going to include the element in the path....
        
        memset(dp,-1,sizeof(dp));
        int x=solve(words,groups,0,-1);
        findPath(words,groups,0,-1);
        return ans;
    }
};
