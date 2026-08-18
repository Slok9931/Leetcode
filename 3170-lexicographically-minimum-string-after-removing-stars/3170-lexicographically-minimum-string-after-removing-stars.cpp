
bool comparePairs(const pair<char, int>& a, const pair<char, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}
class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>,
                       decltype(&comparePairs)>
            pq(comparePairs);

        int n = s.length();

        vector<bool> removed(s.size(), false);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                removed[i] = true;

                if (!pq.empty()) {
                    removed[pq.top().second] = true;
                    pq.pop();
                }
            } else {
                pq.push({s[i], i});
            }
        }

        string result;
        for (int i = 0; i < n; ++i) {
            if (!removed[i]) {
                result += s[i];
            }
        }
        return result;
    }
};
