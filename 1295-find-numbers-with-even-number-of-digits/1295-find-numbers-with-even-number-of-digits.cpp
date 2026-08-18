class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) {
            int digits = 0;
            while(num) {
                digits++;
                num /= 10;
            }
            if(digits % 2 == 0) ans++;
        }
        return ans;
    }
};
