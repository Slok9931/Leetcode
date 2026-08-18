class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> s;
        int mini = INT_MAX, n = nums.size();
        for(int i=0;i<n;i++){
            auto it = s.lower_bound(nums[i]);
            if(it != s.end()) mini = min(mini, abs(*it - nums[i]));
            if(it != s.begin()){
                it--;
                mini = min(mini, abs(*it - nums[i]));
            }
            if(s.size() < indexDiff) s.insert(nums[i]);
            else {
                s.erase(nums[i-indexDiff]);
                s.insert(nums[i]);
            }
        }
        return mini <= valueDiff;
    }
};
