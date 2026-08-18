class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector <int> Dominoes(n, 0);
        int domino = 0;
        for(int i=0;i<n;i++){
            if(dominoes[i] == 'R') domino = n;
            else if(dominoes[i] == 'L') domino = 0;
            else domino = max(domino-1, 0);
            Dominoes[i] += domino;
        }
        domino = 0;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i] == 'L') domino = n;
            else if(dominoes[i] == 'R') domino = 0;
            else domino = max(domino-1, 0);
            Dominoes[i] -= domino;
        }
        string ans = "";
        for(int i:Dominoes){
            if(i > 0) ans += 'R';
            else if(i == 0) ans += '.';
            else ans += 'L';
        }
        return ans;
    }
};
