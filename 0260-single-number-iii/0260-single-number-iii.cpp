class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xo = 0;
        for(int n:nums) xo ^= n;
        int first = 0, second = 0, diff = 0;
        while(((xo >> diff) & 1) != 1) diff++;
        for(int num:nums){
            if(((num >> diff) & 1) == 1) first ^= num;
            else second ^= num;
        }
        return {first, second};
    }
};
