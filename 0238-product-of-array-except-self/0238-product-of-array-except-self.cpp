class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zero = 0;
        for(int i:nums){
            if(i == 0) zero++;
            else prod *= i;
        }
        vector <int> ans;
        if(zero > 1){
            for(int i=0;i<nums.size();i++) ans.push_back(0);
        }
        else if(zero == 1){
            for(int i=0;i<nums.size();i++){
                if(nums[i] == 0) ans.push_back(prod);
                else ans.push_back(0);
            }
        }
        else{
            for(int i=0;i<nums.size();i++) ans.push_back(prod / nums[i]);
        }
        return ans;
    }
};
