class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int t1 = 0, t2 = 1, t3;
        for(int i=2;i<=n;i++){
            t3 = t1 + t2;
            t1 = t2;
            t2 = t3;
        }
        return t3;
    }
};
