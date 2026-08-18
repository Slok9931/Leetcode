class Solution {
public:
    int count = 0;
    bool isPerfectSquare(int a, int b){
        int temp = sqrt(a+b);
        return (temp*temp == (a+b));
    }
    void solve(int curr, vector<int> nums){
        if(curr >= nums.size()){
            count++;
            return;
        }
        for(int i=curr;i<nums.size();i++){
            if(i == curr || nums[i] != nums[curr]){
                swap(nums[curr], nums[i]);
                if(curr == 0 || (curr > 0 && isPerfectSquare(nums[curr-1], nums[curr]))) solve(curr+1, nums);
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, nums);
        return count;
    }
};
