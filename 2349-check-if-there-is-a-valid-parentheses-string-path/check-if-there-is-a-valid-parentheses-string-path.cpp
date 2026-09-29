#include <vector>
class Solution {
    int m, n;
    bool visited[105][105][105];
    bool dfs(int r, int c, int open, const std::vector<std::vector<char>>& grid) {
        open += (grid[r][c] == '(' ? 1 : -1);
        if (open < 0) return false;
        int remaining_steps = (m - 1 - r) + (n - 1 - c);
        if (open > remaining_steps) return false;
        if (r == m - 1 && c == n - 1) {
            return open == 0;
        }
        if (visited[r][c][open]) return false;
        visited[r][c][open] = true;
        if (r + 1 < m && dfs(r + 1, c, open, grid)) return true;
        if (c + 1 < n && dfs(r, c + 1, open, grid)) return true;
        return false;
    }
public:
    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        return dfs(0, 0, 0, grid);
    }
};