class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                index = i - 1;
                break;
            }
        }
        if(index == -1){
            sort(nums.begin(), nums.end());
        }
        else{
            sort(nums.begin() + index + 1, nums.end());
            int mini = INT_MAX, ind = index;
            for(int i=index+1;i<nums.size();i++){
                if(nums[i] > nums[index] && nums[i] < mini){
                    mini = nums[i];
                    ind = i;
                }
            }
            swap(nums[index], nums[ind]);
        }
    }
};
