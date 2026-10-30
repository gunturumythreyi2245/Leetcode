class Solution {
public:
    int solve(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int, int>> water(m);
        for (int i = 0; i < m; ++i) {
            water[i] = {waterStartTime[i], waterDuration[i]};
        }
        sort(water.begin(), water.end());

        vector<int> prefMinDur(m);
        prefMinDur[0] = water[0].second;
        for (int i = 1; i < m; ++i) {
            prefMinDur[i] = min(prefMinDur[i - 1], water[i].second);
        }

        vector<int> suffMinFinish(m);
        suffMinFinish[m - 1] = water[m - 1].first + water[m - 1].second;
        for (int i = m - 2; i >= 0; --i) {
            suffMinFinish[i] = min(suffMinFinish[i + 1], water[i].first + water[i].second);
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int finish1 = landStartTime[i] + landDuration[i];

            int l = 0, r = m - 1, idx = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (water[mid].first <= finish1) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (idx != -1) {
                ans = min(ans, finish1 + prefMinDur[idx]);
            }
            if (idx + 1 < m) {
                ans = min(ans, suffMinFinish[idx + 1]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(
            solve(landStartTime, landDuration, waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration, landStartTime, landDuration)
        );
    }
};