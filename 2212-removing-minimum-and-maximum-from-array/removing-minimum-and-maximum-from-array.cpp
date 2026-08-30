class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minPos = 0, maxPos = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minPos])
                minPos = i;
            if (nums[i] > nums[maxPos])
                maxPos = i;
        }
        int left = min(minPos, maxPos);
        int right = max(minPos, maxPos);
        int option1 = right + 1;
        int option2 = n - left;
        int option3 = (left + 1) + (n - right);
        return min({option1, option2, option3});
    }
};