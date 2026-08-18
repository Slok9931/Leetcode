class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorSum = 0, elem = -1;
        for(int i:nums){
            xorSum ^= i;
            if(elem == -1 && i) elem = i;
        }
        if(!xorSum && elem != -1) return nums.size() - 1;
        else if(xorSum) return nums.size();
        else return 0;
    }
};
