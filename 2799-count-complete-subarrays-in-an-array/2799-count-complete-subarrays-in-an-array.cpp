class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        for(auto i : nums){
            st.insert(i);
        }
        int k = st.size();
        queue<int> q;
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0  ; i < nums.size() ; i++){
             
             if(q.size() < k || mp.size() < k){
                q.push(i);
                mp[nums[i]]++;
             }
            
            if(mp.size() == k){
                ans+= nums.size() - i;
                while(q.size() >= k && mp.size() == k){
                    int f= q.front();
                    q.pop();
                    if(--mp[nums[f]] == 0){
                        mp.erase(nums[f]);
                    } else {
                        ans += nums.size() - i;
                    }
                }
            }
        }
        return ans;
    }
};
