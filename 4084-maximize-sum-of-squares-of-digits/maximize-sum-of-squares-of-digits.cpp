#include <string>
#include <algorithm>
class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        if (sum > (long long)num * 9) {
            return "";
        }
        
        std::string res(num, '0');
        for (int i = 0; i < num; ++i) {
            int take = std::min(9, sum);
            res[i] = '0' + take;
            sum -= take;
            if (sum == 0) {
                break;
            }
        }
        
        return res;
    }
};
