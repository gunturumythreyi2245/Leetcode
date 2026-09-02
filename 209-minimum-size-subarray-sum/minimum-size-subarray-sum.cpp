class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int currentSum = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            currentSum += nums[right]; // Expand the window to the right
            // Shrink the window from the left as long as the condition is met
            while (currentSum >= target) {
                minLength = min(minLength, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }
        // If minLength was never updated, no valid subarray exists
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
