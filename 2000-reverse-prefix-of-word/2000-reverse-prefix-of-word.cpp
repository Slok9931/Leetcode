class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = word.find(ch) + 1;
        reverse(word.begin(), word.begin()+index);
        return word;
    }
};
