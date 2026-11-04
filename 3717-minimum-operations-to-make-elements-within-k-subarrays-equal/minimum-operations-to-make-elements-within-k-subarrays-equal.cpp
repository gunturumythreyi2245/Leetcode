#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> minOps = getMinOps(nums, x);
        int m = minOps.size();
        
        vector<vector<long long>> dp(k + 1, vector<long long>(m + 1, 1e18));
        fill(dp[0].begin(), dp[0].end(), 0);
        
        for (int i = 1; i <= k; ++i) {
            long long minPrev = dp[i - 1][0];
            for (int j = 0; j < m; ++j) {
                if (j >= x) {
                    minPrev = min(minPrev, dp[i - 1][j - x + 1]);
                }
                dp[i][j + 1] = min(dp[i][j], minPrev + minOps[j]);
            }
        }
        
        return dp[k][m];
    }

private:
    vector<long long> getMinOps(const vector<int>& nums, int x) {
        vector<long long> minOps;
        multiset<int> lower;
        multiset<int> upper;
        long long lowerSum = 0;
        long long upperSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int inNum = nums[i];
            if (lower.empty() || inNum <= *lower.rbegin()) {
                lower.insert(inNum);
                lowerSum += inNum;
            } else {
                upper.insert(inNum);
                upperSum += inNum;
            }
            
            if (i >= x) {
                int outNum = nums[i - x];
                auto it = lower.find(outNum);
                if (it != lower.end()) {
                    lower.erase(it);
                    lowerSum -= outNum;
                } else {
                    upper.erase(upper.find(outNum));
                    upperSum -= outNum;
                }
            }
            
            if (lower.size() < upper.size()) {
                int val = *upper.begin();
                upper.erase(upper.begin());
                lower.insert(val);
                upperSum -= val;
                lowerSum += val;
            } else if (lower.size() - upper.size() > 1) {
                int val = *lower.rbegin();
                lower.erase(prev(lower.end()));
                upper.insert(val);
                lowerSum -= val;
                upperSum += val;
            }
            
            if (i >= x - 1) {
                long long median = *lower.rbegin();
                long long ops = (median * lower.size() - lowerSum) + (upperSum - median * upper.size());
                minOps.push_back(ops);
            }
        }
        
        return minOps;
    }
};
