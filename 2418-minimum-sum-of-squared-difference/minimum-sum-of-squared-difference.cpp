#include <vector>
#include <cmath>
#include <algorithm>
class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long total_k = (long long)k1 + k2;
        std::vector<long long> count(100001, 0);
        long long max_diff = 0;
        long long initial_diff_sum = 0;
        for (int i = 0; i < n; ++i) {
            int diff = std::abs(nums1[i] - nums2[i]);
            if (diff > 0) {
                count[diff]++;
                max_diff = std::max(max_diff, (long long)diff);
            }
            initial_diff_sum += diff;
        }
        if (initial_diff_sum <= total_k) {
            return 0;
        }
        for (long long d = max_diff; d > 0 && total_k > 0; --d) {
            if (count[d] == 0) continue;
            long long take = std::min(total_k, count[d]);
            count[d] -= take;
            count[d - 1] += take;
            total_k -= take;
        }
        long long min_sum = 0;
        for (long long d = 1; d <= max_diff; ++d) {
            if (count[d] > 0) {
                min_sum += count[d] * d * d;
            }
        }
        return min_sum;
    }
};