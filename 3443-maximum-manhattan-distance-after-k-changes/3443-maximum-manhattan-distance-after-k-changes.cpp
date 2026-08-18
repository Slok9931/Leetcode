class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == 'N') north++;
            else if (c == 'S') south++;
            else if (c == 'E') east++;
            else if (c == 'W') west++;

            int vertical = abs(north - south);
            int horizontal = abs(east - west);
            int manhattan = vertical + horizontal;

            int used = min(k, i + 1);
            int possible = manhattan + 2 * used;

            int maxPossible = min(i + 1, manhattan + 2 * k);
            ans = max(ans, min(possible, maxPossible));
        }

        return ans;
    }
};
