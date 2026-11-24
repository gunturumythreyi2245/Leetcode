#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int max_len = 2;
        long long max_possible_prod = 36288000LL; 

        for (int i = 0; i < n; ++i) {
            long long prod = nums[i];
            long long g = nums[i];
            long long l = nums[i];

            for (int j = i + 1; j < n; ++j) {
                if (prod > max_possible_prod / nums[j]) break;
                
                prod *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);

                if (prod == l * g) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        return max_len;
    }
};