class Solution {
public:
    bool solve(int nums, int t){
        int ans = 1;
        while(nums != 0){
            ans *= nums % 10;
            nums /= 10;
        }
        return ans % t == 0;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(solve(n, t)) return n;
            n++;
        }
        return -1;
    }
};
