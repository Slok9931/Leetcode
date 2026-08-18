class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> val(n);
        vector<int> degree(n);
        for(auto i:roads){
            degree[i[0]]++;
            degree[i[1]]++;
        }
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++) v.push_back({degree[i], i});
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int count = n;
        for(auto i:v){
            val[i.second] = count;
            count--;
        }
        long long sum = 0;
        for(auto i:roads) sum += val[i[0]] + val[i[1]];
        return sum;
    }
};
