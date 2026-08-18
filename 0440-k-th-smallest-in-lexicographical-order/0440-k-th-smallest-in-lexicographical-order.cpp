class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--; // We start with 1, so decrease k by 1

        while (k > 0) {
            long long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }

private:
    long long countSteps(int n, long long first, long long last) {
        long long steps = 0;
        while (first <= n) {
            steps += min((long long)n + 1, last) - first;
            first *= 10;
            last *= 10;
        }
        return steps;
    }
};
