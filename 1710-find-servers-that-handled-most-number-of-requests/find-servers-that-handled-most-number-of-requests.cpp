#include <vector>
#include <set>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
        // Min-heap to store (end_time, server_id)
        using Pair = std::pair<long long, int>;
        std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> busy;

        // Set to store currently available server IDs
        std::set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        std::vector<int> request_count(k, 0);
        int n = arrival.size();

        for (int i = 0; i < n; ++i) {
            long long current_time = arrival[i];

            // Free up servers whose current task is completed by arrival[i]
            while (!busy.empty() && busy.top().first <= current_time) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // If no servers are available, drop the request
            if (available.empty()) {
                continue;
            }

            // Search for the first available server starting from (i % k)
            auto it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin(); // Wrap around to the beginning
            }

            int server_id = *it;
            request_count[server_id]++;
            
            // Mark server as busy until arrival[i] + load[i]
            busy.push({current_time + load[i], server_id});
            available.erase(it);
        }

        // Find the maximum requests handled by any server
        int max_requests = *std::max_element(request_count.begin(), request_count.end());

        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_requests) {
                result.push_back(i);
            }
        }

        return result;
    }
};