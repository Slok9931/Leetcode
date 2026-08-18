class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>>v;
        unordered_map<char, int> freq;
        for(char c:s) freq[c]++;
        for(auto it:freq){
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end());
        string ans = "";
        for(int i=v.size()-1;i>=0;i--){
            int j = v[i].first;
            while(j > 0){
                ans += v[i].second;
                j--;
            }
        }
        return ans;
    }
};
