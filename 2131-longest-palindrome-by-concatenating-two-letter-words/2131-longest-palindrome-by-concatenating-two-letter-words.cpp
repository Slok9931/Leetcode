class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        int ans = 0;
        unordered_map<string, int> mp;
        unordered_map<string, int> sameMap;
        int mxOddCnt = 0;

        for(auto &word: words) {

            if(word[1] == word[0]) {
                sameMap[word] += 2;
                continue;
            }

            string tmp = word;
            reverse(tmp.begin(), tmp.end());

            if(mp.find(tmp) != mp.end()) {
                ans += 4;
                mp[tmp] -= 2;
                if(mp[tmp] == 0) {
                    mp.erase(tmp);
                }

            } else {
                mp[word] += 2;
            }

        }

        bool taken = false;

        for(auto &[word, rep]: sameMap) {
            int tmpcnt = rep / 2;
            if(tmpcnt % 2 == 1) {
                mxOddCnt = max(mxOddCnt, rep);
            }
        }
        for(auto &[word, rep]: sameMap) {

            int tmpCnt = rep / 2;
            if(tmpCnt % 2 == 0) {
                ans += rep;
            } else {
                if(rep == mxOddCnt && !taken) {
                    ans += rep;
                    taken = true;
                } else {
                    ans += (rep - 2);
                }
            }
        }

        return ans;

    }
};
