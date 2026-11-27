#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int max_f = 0;
        for (const auto& item : items) {
            max_f = max(max_f, item[0]);
        }

        vector<int> freq(max_f + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }

        vector<int> div_count(max_f + 1, 0);
        for (int f = 1; f <= max_f; ++f) {
            for (int m = f; m <= max_f; m += f) {
                div_count[f] += freq[m];
            }
        }

        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; ++i) {
            int f = items[i][0];
            int p = items[i][1];
            int first_gain = div_count[f];

            vector<int> next_dp = dp;
            for (int b = p; b <= budget; ++b) {
                next_dp[b] = max(next_dp[b], dp[b - p] + first_gain);
                if (b >= 2 * p) {
                    next_dp[b] = max(next_dp[b], next_dp[b - p] + 1);
                }
            }
            dp = move(next_dp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};