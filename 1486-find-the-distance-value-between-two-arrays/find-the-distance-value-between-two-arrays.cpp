#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
      
        std::sort(arr2.begin(), arr2.end());
        int distanceValue = 0;

        for (int x : arr1) {
           
            auto it = std::lower_bound(arr2.begin(), arr2.end(), x - d);
            
            bool isValid = true;
            
            
            if (it != arr2.end() && std::abs(*it - x) <= d) {
                isValid = false;
            }
           
            if (isValid && it != arr2.begin() && std::abs(*(it - 1) - x) <= d) {
                isValid = false;
            }
            
            if (isValid) {
                distanceValue++;
            }
        }

        return distanceValue;
    }
};