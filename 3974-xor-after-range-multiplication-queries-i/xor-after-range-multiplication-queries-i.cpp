class Solution {
public:
    long long xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            for (int i = l; i <= r; i += k) {
                nums[i] = (long long)nums[i] * v % 1000000007;
            }
        }
        long long ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }
};