class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long mxsum = 0, count = 0;
        long long minchange=INT_MAX;
        for (long long it:nums) {
            mxsum += max(it ^ k, it);//either changed one or not changed one whatever is maximum 
            count += (it ^ k) > it;//how many hypes are benificial
            minchange=min(minchange,abs(it-(it^k)));//minimum benificial hype
        }
        if(!(count%2)) return mxsum;//change all the nodes that are giving hype
        else return (mxsum - minchange);
    }
};
