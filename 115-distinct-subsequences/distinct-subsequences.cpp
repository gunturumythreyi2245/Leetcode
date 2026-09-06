#include <string>
#include <vector>
class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int srcLen = s.length();
        int tgtLen = t.length();
        std::vector<unsigned long long> counts(tgtLen + 1, 0);
        counts[0] = 1;
        for (int i = 1; i <= srcLen; ++i) {
            for (int j = tgtLen; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    counts[j] += counts[j - 1];
                }
            }
        }
        return counts[tgtLen];
    }
};
