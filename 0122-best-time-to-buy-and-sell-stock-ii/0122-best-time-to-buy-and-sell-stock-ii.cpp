class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int x = prices[0];
        int ans = 0;
        for(int i=1;i<prices.size();i++){
            if(x > prices[i]) x = prices[i];
            else{
                ans += prices[i] - x;
                x = prices[i];
            }
        }
        return ans;
    }
};
