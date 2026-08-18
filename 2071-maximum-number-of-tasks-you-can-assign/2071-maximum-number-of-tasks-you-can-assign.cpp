class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int n = tasks.size();
        int m = workers.size();
        int left = 0, right = min(n, m);
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(mid, tasks, workers, pills, strength)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
    
private:
    bool isPossible(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        if (k == 0) return true;
        int n = tasks.size();
        int m = workers.size();
        if (k > n || k > m) return false;
        
        vector<int> selected_tasks(tasks.begin(), tasks.begin() + k);
        vector<int> selected_workers(workers.end() - k, workers.end());
        sort(selected_tasks.begin(), selected_tasks.end());
        sort(selected_workers.begin(), selected_workers.end());
        
        multiset<int> worker_set(selected_workers.begin(), selected_workers.end());
        
        for (int i = k - 1; i >= 0; --i) {
            int t = selected_tasks[i];
            if (worker_set.empty()) return false;
            
            auto largest_it = prev(worker_set.end());
            int largest = *largest_it;
            
            if (largest >= t) {
                worker_set.erase(largest_it);
            } else {
                if (pills <= 0) return false;
                int required = t - strength;
                auto it = worker_set.lower_bound(required);
                if (it != worker_set.end()) {
                    worker_set.erase(it);
                    pills--;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};
