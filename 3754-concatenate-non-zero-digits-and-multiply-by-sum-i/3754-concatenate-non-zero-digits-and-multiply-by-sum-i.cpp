class Solution {
public:
    long long sumAndMultiply(int n) {
        long long int x = 0, sum = 0, i = 0;
        while(n){
            int digit = n % 10;
            n /= 10;
            if(!digit) continue;
            if(x == 0){
                x = digit;
                sum = digit;
                i++;
            }
            else{
                x += digit * pow(10, i);
                sum += digit;
                i++;
            }
        }
        return x * sum;
    }
};
