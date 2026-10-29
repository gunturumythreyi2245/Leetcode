class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, bitMask;
    int curPos;

    int dfs1(int v, int p, int d) {
        int size = 1;
        int maxSubtree = 0;
        parent[v] = p;
        depth[v] = d;
        for (int c : adj[v]) {
            if (c != p) {
                int subtreeSize = dfs1(c, v, d + 1);
                size += subtreeSize;
                if (subtreeSize > maxSubtree) {
                    maxSubtree = subtreeSize;
                    heavy[v] = c;
                }
            }
        }
        return size;
    }

    void dfs2(int v, int h) {
        head[v] = h;
        pos[v] = ++curPos;
        if (heavy[v] != -1) {
            dfs2(heavy[v], h);
        }
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v]) {
                dfs2(c, c);
            }
        }
    }

    void updateBit(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bitMask[idx] ^= val;
        }
    }

    int queryBit(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum ^= bitMask[idx];
        }
        return sum;
    }

    int queryRange(int l, int r) {
        return queryBit(r) ^ queryBit(l - 1);
    }

    int queryPath(int a, int b) {
        int res = 0;
        while (head[a] != head[b]) {
            if (depth[head[a]] < depth[head[b]]) {
                swap(a, b);
            }
            res ^= queryRange(pos[head[a]], pos[a]);
            a = parent[head[a]];
        }
        if (depth[a] > depth[b]) {
            swap(a, b);
        }
        res ^= queryRange(pos[a], pos[b]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        bitMask.assign(n + 1, 0);
        curPos = 0;

        dfs1(0, -1, 0);
        dfs2(0, 0);

        for (int i = 0; i < n; ++i) {
            updateBit(pos[i], 1 << (s[i] - 'a'));
        }

        vector<bool> ans;
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int oldVal = 1 << (s[u] - 'a');
                int newVal = 1 << (c - 'a');
                updateBit(pos[u], oldVal ^ newVal);
                s[u] = c;
            } else if (type == "query") {
                int u, v;
                ss >> u >> v;
                int pathMask = queryPath(u, v);
                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};