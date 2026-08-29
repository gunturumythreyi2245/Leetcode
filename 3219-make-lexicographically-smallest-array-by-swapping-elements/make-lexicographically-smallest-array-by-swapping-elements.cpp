class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> index(n);
        for (int i=0;i<n;i++) {
            index[i] = i;
        }
        sort(index.begin(), index.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        vector<int> ans(n);
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n &&
                   nums[index[j]] - nums[index[j - 1]] <= limit) {
                j++;
            }
            vector<int> positions;
            for (int k = i; k < j; k++) {
                positions.push_back(index[k]);
            }
            sort(positions.begin(), positions.end());
            for (int k = 0; k < positions.size(); k++) {
                ans[positions[k]] = nums[index[i + k]];
            }
            i = j;
        }
        return ans;
    }
};