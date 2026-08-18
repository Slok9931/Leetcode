class Solution {
public:
    bool isBalanced(int num) {
        vector<int> freq(10, 0);
        int temp = num;
        while (temp > 0) {
            freq[temp % 10]++;
            temp /= 10;
        }
        for (int d = 0; d <= 9; d++) {
            if (freq[d] > 0 && freq[d] != d)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        int num = n + 1;
        while (true) {
            if (isBalanced(num))
                return num;
            num++;
        }
        return -1;
    }
};
