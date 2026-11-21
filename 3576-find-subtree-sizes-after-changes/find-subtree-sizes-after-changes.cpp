class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> new_parent = parent;
        vector<int> last_seen(26, -1);

        auto dfs1 = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev = last_seen[c];
            if (prev != -1) {
                new_parent[u] = prev;
            }
            last_seen[c] = u;
            for (int v : adj[u]) {
                self(self, v);
            }
            last_seen[c] = prev;
        };

        dfs1(dfs1, 0);

        vector<vector<int>> new_adj(n);
        for (int i = 1; i < n; ++i) {
            new_adj[new_parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        auto dfs2 = [&](auto& self, int u) -> void {
            for (int v : new_adj[u]) {
                self(self, v);
                ans[u] += ans[v];
            }
        };

        dfs2(dfs2, 0);
        return ans;
    }
};