class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        for(string s:strs){
            vector<int> count(26, 0);
            for(char c:s) count[c - 'a']++;
            string key;
            for(int num:count) key += to_string(num) + '#';
            ans[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto i:ans) res.push_back(i.second);
        return res;
    }
};
