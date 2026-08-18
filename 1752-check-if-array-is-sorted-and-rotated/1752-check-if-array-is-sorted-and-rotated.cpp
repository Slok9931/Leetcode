class Solution {
public:
    bool check(vector<int>& nums) {
        bool dec = false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1]){
                if(!dec) dec = true;
                else return false;
            }
        }
        if((dec && nums[nums.size()-1] <= nums[0]) || (!dec && nums[nums.size()-1] >= nums[0])) return true;
        else return false;
    }
};
