class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int qLen = queries.size();
        vector<pair<int, int>> sortedQueries(qLen);
        for (int i = 0; i < qLen; ++i) {
            sortedQueries[i] = {queries[i], i};
        }

        sort(sortedQueries.begin(), sortedQueries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> ans(qLen);
        unordered_map<int, int> activeCount;
        int activeServers = 0;
        int left = 0, right = 0;
        int logLen = logs.size();

        for (int i = 0; i < qLen; ++i) {
            int qTime = sortedQueries[i].first;
            int qIdx = sortedQueries[i].second;
            int startTime = qTime - x;

            while (right < logLen && logs[right][1] <= qTime) {
                int server = logs[right][0];
                if (activeCount[server] == 0) {
                    activeServers++;
                }
                activeCount[server]++;
                right++;
            }

            while (left < logLen && logs[left][1] < startTime) {
                int server = logs[left][0];
                activeCount[server]--;
                if (activeCount[server] == 0) {
                    activeServers--;
                }
                left++;
            }

            ans[qIdx] = n - activeServers;
        }

        return ans;
    }
};