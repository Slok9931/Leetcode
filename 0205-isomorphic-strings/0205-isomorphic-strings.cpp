class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, char> rev_mp;
        for (int i = 0; i < s.size(); i++) {
            if ((mp.count(s[i]) && mp[s[i]] != t[i]) || 
                (rev_mp.count(t[i]) && rev_mp[t[i]] != s[i])) {
                return false;
            }
            mp[s[i]] = t[i];
            rev_mp[t[i]] = s[i];
        }
        return true;
    }
};
