class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size(), i = 0, j = 1;
        if(numFriends == 1) return word;
        while(j < n){
            while(j < n && word[i] > word[j]) j++;
            if(j < n && word[i] < word[j]) i = j;
            else{
                int k = 0;
                while(j + k < n && word[i+k] == word[j+k]) k++;
                if(j + k < n && word[i+k] < word[j+k]) i = j;
            }
            j++;
        }
        return word.substr(i, min(n - i, n - numFriends + 1));
    }
};
