class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size() , m = nums2.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<>> pq;
        for(int i = 0; i < n ; i++){
            pq.emplace(nums1[i]+nums2[0],i,0);
        }
        vector<vector<int>> ans;
        while(k--){
            auto [sum, i1, i2] = pq.top();
            pq.pop();
            ans.push_back({nums1[i1],nums2[i2]});
            if(i2 < m-1){
                pq.emplace(nums1[i1]+nums2[i2+1],i1,i2+1);
            }
        }
        return ans;
    }
};
