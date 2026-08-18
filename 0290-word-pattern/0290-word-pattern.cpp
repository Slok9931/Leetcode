class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ctos;
        unordered_map<string, char> stoc;
        istringstream iss(s);
        string word;
        int i = 0;

        while (iss >> word) {
            if (i >= pattern.length()) return false;

            char c = pattern[i];

            if (ctos.count(c) && ctos[c] != word) return false;
            if (stoc.count(word) && stoc[word] != c) return false;

            ctos[c] = word;
            stoc[word] = c;
            i++;
        }

        return i == pattern.length();
    }
};
