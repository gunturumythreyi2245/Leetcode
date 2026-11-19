class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (i != pos) {
                    swap(nums[pos], nums[i]);
                }
                ++pos;
            }
        }
    }
};