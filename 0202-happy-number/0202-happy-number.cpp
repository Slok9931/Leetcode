class Solution {
public:
    int solve(int n){
        int ans = 0;
        while(n > 0){
            int x = n % 10;
            ans += x * x;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> visit;
        while(visit.find(n) == visit.end()){
            visit.insert(n);
            n = solve(n);
            if(n == 1) return true;
        }
        return false;
    }
};
