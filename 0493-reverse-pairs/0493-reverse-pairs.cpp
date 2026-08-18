class Solution {
public:
    int merge(vector <int> &arr, int low, int mid, int high){
        int left = low, right = mid+1;
        vector <int> ans;
        int count = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)arr[i] > 2LL * arr[j])
                j++;
            count += (j - (mid + 1));
        }
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]) ans.push_back(arr[left++]);
            else ans.push_back(arr[right++]);
        }
        while(left <= mid) ans.push_back(arr[left++]);
        while(right <= high) ans.push_back(arr[right++]);
        for(int i=low;i<=high;i++) arr[i] = ans[i-low];
        return count;
    }
    int solve(vector <int> &arr, int low, int high){
        if(low >= high) return 0;
        int mid = low + (high - low) / 2;
        int ans = 0;
        ans += solve(arr, low, mid);
        ans += solve(arr, mid+1, high);
        ans += merge(arr, low, mid, high);
        return ans;
    }
    int reversePairs(vector<int>& arr) {
        int n = arr.size();
        return solve(arr, 0, n-1);
    }
};
