class Solution {
public:
    bool isValid(string token) {
        int hyphen = 0, punct = 0;
        for (int i = 0; i < token.size(); i++) {
            char c = token[i];
            if (isdigit(c)) return false;
            if (c == '-') {
                hyphen++;
                if (hyphen > 1) return false;
                if (i == 0 || i == token.size() - 1) return false;
                if (!islower(token[i - 1]) || !islower(token[i + 1]))
                    return false;
            }
            if (c == '!' || c == '.' || c == ',') {
                punct++;
                if (punct > 1) return false;
                if (i != token.size() - 1) return false;
            }
        }
        return true;
    }
    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string token;
        int count = 0;
        while (ss >> token) {
            if (isValid(token)) count++;
        }
        return count;
    }
};
