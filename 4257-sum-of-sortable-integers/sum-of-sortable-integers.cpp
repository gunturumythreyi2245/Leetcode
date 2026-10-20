#include <vector>
#include <algorithm>

class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();

        std::vector<int> drop_pref(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            drop_pref[i + 1] = drop_pref[i] + (nums[i] > nums[i + 1] ? 1 : 0);
        }

        auto get_drops = [&](int l, int r) {
            if (l >= r) return 0;
            return drop_pref[r] - drop_pref[l];
        };

        long long total_sum = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool sortable = true;
            int prev_max = -1;

            for (int i = 0; i < n; i += k) {
                int block_drops = get_drops(i, i + k - 1);

                int block_min = nums[i], block_max = nums[i];
                for (int j = i; j < i + k; ++j) {
                    block_min = std::min(block_min, nums[j]);
                    block_max = std::max(block_max, nums[j]);
                }

                if (prev_max != -1 && block_min < prev_max) {
                    sortable = false;
                    break;
                }

                if (block_drops == 0) {
                } else if (block_drops == 1) {
                    if (nums[i] < nums[i + k - 1]) {
                        sortable = false;
                        break;
                    }
                } else {
                    sortable = false;
                    break;
                }

                prev_max = block_max;
            }

            if (sortable) {
                total_sum += k;
            }
        }

        return total_sum;
    }
};