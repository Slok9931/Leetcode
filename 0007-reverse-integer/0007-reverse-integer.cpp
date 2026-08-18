class Solution {
public:
    int reverse(int y) {
        bool neg = false;
        long long x = y;
        if(x < 0) {
            neg = true;
            x *= -1;
        }
        long long rev = 0;
        while(x > 0){
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        if(rev > INT_MAX) rev = 0;
        if(neg) rev *= -1;
        return rev;
    }
};
