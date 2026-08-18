class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int mask = 0;
        for(int i:nums) mask |= i;
        return mask + 1;
    }
};
