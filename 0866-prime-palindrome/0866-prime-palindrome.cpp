class Solution {
public:
    bool isPrime(int n){
        if(n == 0 || n == 1) return false;
        if(n == 2) return true;
        for(int i=2;i*i<=n;i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    int primePalindrome(int n) {
        if(n <= 2) return 2;
        if(n >= 8 && n <= 11) return 11;
        for(int i=1;i<=100000;i++){
            string s = to_string(i);
            string r = s;
            reverse(r.begin(), r.end());
            int x = stoi(s + r.substr(1));
            if(x >= n && isPrime(x)) return x;
        }
        return 0;
    }
};
