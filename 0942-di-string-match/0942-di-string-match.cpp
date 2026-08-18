class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i = 0, d = s.size();
        vector <int> ans;
        for(char c:s){
            if(c == 'I'){
                ans.push_back(i);
                i++;
            }
            else{
                ans.push_back(d);
                d--;
            }
        }
        ans.push_back(i);
        return ans;
    }
};
