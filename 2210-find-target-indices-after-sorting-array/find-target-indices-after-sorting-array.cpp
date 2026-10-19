#include <vector>

class Solution {
public:
    std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        int less_than = 0;
        int count = 0;
        
        for (int num : nums) {
            if (num < target) {
                less_than++;
            } else if (num == target) {
                count++;
            }
        }
        
        std::vector<int> result;
        for (int i = 0; i < count; i++) {
            result.push_back(less_than + i);
        }
        
        return result;
    }
};