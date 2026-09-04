class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        // right[i] = minimum from i to n-1
        vector<int> right(n);

        right[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(right[i + 1], nums[i]);
        }

        // Maximum from left
        int left = nums[0];

        for (int i = 0; i < n; i++) {

            left = max(left, nums[i]);

            // instability = max(left part) - min(right part)
            if (left - right[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};