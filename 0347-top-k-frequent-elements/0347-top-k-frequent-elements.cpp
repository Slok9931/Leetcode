class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_map<int, int> freq;
        vector<int> ans;
        for(int i:nums) freq[i]++;
        for(auto i:freq){
            if(minHeap.size() < k) minHeap.push({i.second, i.first});
            else {
                auto x = minHeap.top();
                if(x.first < i.second){
                    minHeap.pop();
                    minHeap.push({i.second, i.first});
                }
            }
        }
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};
