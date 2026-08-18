class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for(char c:s) if(c == '1') ones++;
        s = "1" + s + "1";
        int n = s.size(), i = 0;
        int ans = ones;
        while(i < n && s[i] == '1') i++;
        int leftZeros = 0;
        while(i < n && s[i] == '0'){
            leftZeros++;
            i++;
        }
        while(i < n){
            int midOnes = 0;
            while(i < n && s[i] == '1'){
                midOnes++;
                i++;
            }
            if(midOnes == 0) break;
            int rightZeros = 0;
            while(i < n && s[i] == '0'){
                rightZeros++;
                i++;
            }
            if(rightZeros == 0) break;
            ans = max(ans, ones + leftZeros + rightZeros);
            leftZeros = rightZeros;
        }
        return ans;
    }
};
