class Solution {
public:
    int missingInteger(vector<int>& nums) {
        map<int, int> freq;
        int prefSum = nums[0];
        bool flag = true;
        freq[nums[0]]++;
        for(int i=1;i<nums.size();i++){
            freq[nums[i]]++;
            if(flag && nums[i] == nums[i-1] + 1) prefSum += nums[i];
            else flag = false;
        }
        while(true){
            if(freq.find(prefSum) == freq.end()) return prefSum;
            prefSum++;
        }
        return -1;
    }
};