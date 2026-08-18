class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        // For maximum value (a): Replace the first non-9 digit with 9
        string maxStr = s;
        for (char& c : maxStr) {
            if (c != '9') {
                char toReplace = c;
                for (char& d : maxStr) {
                    if (d == toReplace) d = '9';
                }
                break;
            }
        }
        
        // For minimum value (b)
        string minStr = s;
        // First digit case: If it's not 1, replace with 1 (but first digit can't be 0)
        if (minStr[0] != '1') {
            char toReplace = minStr[0];
            for (char& d : minStr) {
                if (d == toReplace) d = '1';
            }
        } else {
            // If first digit is 1, find the first non-0, non-1 digit and replace with 0
            for (int i = 1; i < minStr.size(); i++) {
                if (minStr[i] != '0' && minStr[i] != '1') {
                    char toReplace = minStr[i];
                    for (char& d : minStr) {
                        if (d == toReplace) d = '0';
                    }
                    break;
                }
            }
        }
        
        // Convert strings back to integers
        int a = stoi(maxStr);
        int b = stoi(minStr);
        
        return a - b;
    }
};
