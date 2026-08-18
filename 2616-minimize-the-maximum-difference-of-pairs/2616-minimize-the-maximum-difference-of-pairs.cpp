class Solution {
public:
    // Check if we can form at least p pairs with max difference <= maxDiff
    bool canFormPairs(vector<int>& nums, int maxDiff, int p) {
        int count = 0;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2;  // skip both elements to ensure non-overlapping
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());

        int low = 0, high = nums.back() - nums.front();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFormPairs(nums, mid, p)) {
                ans = mid;        // Possible answer, try smaller maxDiff
                high = mid - 1;
            } else {
                low = mid + 1;    // Not enough pairs, increase maxDiff
            }
        }

        return ans;
    }
};
