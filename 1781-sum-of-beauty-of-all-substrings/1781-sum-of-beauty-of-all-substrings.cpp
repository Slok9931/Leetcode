class Solution {
public:
    int beauty(string s){
        vector <int> freq(26, 0);
        for(char c:s) freq[c - 'a']++;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0;i<26;i++){
            if(freq[i] > maxi) maxi = freq[i];
            if(freq[i] < mini && freq[i] > 0) mini = freq[i];
        }
        return maxi - mini;
    }
    int beautySum(string s) {
        int sum = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                sum += beauty(s.substr(i,j-i+1));
            }
        }
        return sum;
    }
};
