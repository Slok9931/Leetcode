class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long int nn = n;
        if(nn < 0) nn *= -1;
        while(nn){
            if(nn % 2 == 1){
                ans *= x;
                nn--;
            }
            else{
                x = x*x;
                nn /= 2;
            }
        }
        if(n < 0) ans = (double)(1) / ans;
        return ans;
    }
};
