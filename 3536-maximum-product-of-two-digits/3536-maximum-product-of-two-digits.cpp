class Solution {
public:
    int maxProduct(int n) {
        int first = 0, second = 0;
        while(n){
            int x = n % 10;
            n /= 10;
            if(x > first){
                second = first;
                first = x;
            }
            else if(first >= x && x > second) second = x;
        }
        return first * second;
    }
};
