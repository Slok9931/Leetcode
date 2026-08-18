class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, can1 = INT_MIN, can2 = INT_MIN;
        int n = nums.size();
        for(int i:nums){
            if(i == can1) count1++;
            else if(i == can2) count2++;
            else if(count1 == 0){
                can1 = i;
                count1 = 1;
            }
            else if(count2 == 0){
                can2 = i;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int i:nums){
            if(i == can1) count1++;
            else if(i == can2) count2++;
        }
        int ans1 = -101, ans2 = -101;
        if(count1 > n/3) ans1 = can1;
        if(count2 > n/3) ans2 = can2;
        if(ans1 == -101 && ans2 == -101) return {};
        else if(ans1 == -101) return {ans2};
        else if(ans2 == -101) return {ans1};
        else return {ans1, ans2};
    }
};
