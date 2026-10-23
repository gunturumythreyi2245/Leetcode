class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        unsigned n = nums.size();
        int k0 = std::bit_ceil(n) - 1;
        int k = k0;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (x != i) {
                k &= x;
            }
        }
        return k == k0 ? 0 : k;
    }
};