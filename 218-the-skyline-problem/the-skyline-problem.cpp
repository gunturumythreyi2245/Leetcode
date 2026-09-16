#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2]}); 
            events.push_back({b[1], b[2]}); 
        }
        sort(events.begin(), events.end());
        vector<vector<int>> result;
        multiset<int> heights = {0}; 
        int max_height = 0; 
        for (const auto& [x, h] : events) {
            if (h < 0) {
                heights.insert(-h);
            } else {
                heights.erase(heights.find(h));
            }
            int current_max = *heights.rbegin();
            if (current_max != max_height) {
                result.push_back({x, current_max});
                max_height = current_max;
            }
        }  
        return result;
    }
};