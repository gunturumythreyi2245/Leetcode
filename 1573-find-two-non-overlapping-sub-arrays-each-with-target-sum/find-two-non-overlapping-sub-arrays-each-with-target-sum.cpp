class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX / 2); 
        int current_sum = 0;
        int left = 0;
        int ans = INT_MAX;
        int current_min = INT_MAX / 2;
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }
            if (current_sum == target) {
                int len = right - left + 1;
                if (left > 0 && min_len[left - 1] != INT_MAX / 2) {
                    ans = min(ans, len + min_len[left - 1]);
                }
                current_min = min(current_min, len);
            }
            min_len[right] = current_min;
        }
        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};