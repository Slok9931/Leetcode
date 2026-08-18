class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> have;
        for(int i=0;i<nums.size();i++) have[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++) {
            if(have.find(target - nums[i]) != have.end() && have[target - nums[i]] != i){
                ans.push_back(have[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
        }
        return { -1, -1};
    }
};
