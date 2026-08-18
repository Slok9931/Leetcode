class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int MAX = 2048;
        vector<bool> one(MAX,false);
        vector<bool> two(MAX,false);
        vector<bool> three(MAX,false);
        for(int i : nums){
            for(int j=0;j<MAX;j++){
                if(one[j]) two[j ^ i] = true;
            }
            one[i] = true;
        }
        for(int i : nums){
            for(int j=0;j<MAX;j++){
                if(two[j]) three[j ^ i] = true;
            }
        }
        int ans = 0;
        for(bool i:three) ans += i;
        return ans;
    }
};
