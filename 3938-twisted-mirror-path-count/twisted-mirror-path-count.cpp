#include <vector>

class Solution {
public:
    int uniquePaths(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        // Helper function to trace the exact path of a jump from (start_r, start_c) with initial direction (dr, dc)
        auto get_landing = [&](int r, int c, int dr, int dc) {
            while (true) {
                r += dr;
                c += dc;
                
                // Check if out of bounds
                if (r < 0 || r >= m || c < 0 || c >= n) {
                    return std::make_pair(-1, -1);
                }
                
                // If it hits an empty cell, this is where it lands
                if (grid[r][c] == 0) {
                    return std::make_pair(r, c);
                }
                
                // If it hits a mirror (grid[r][c] == 1):
                // Reflection rules:
                // - moving horizontally (dc != 0) -> reflects vertically (dc becomes 0, dr becomes 1 or -1 depending on current row or standard turn down)
                // Let's check standard problem behavior for mirrors:
                // Moving right into a mirror -> turns down (dr = 1, dc = 0)
                // Moving left into a mirror -> turns up/down? Usually grids are only right/down movements.
                // Since we only ever move right or down from the current cell:
                if (dr == 0 && dc == 1) { // moving right into mirror
                    dr = 1; 
                    dc = 0; // turns down
                } else if (dr == 1 && dc == 0) { // moving down into mirror
                    dr = 0; 
                    dc = 1; // turns right
                }
            }
        };

        // jump[i][j][0] -> landing if moving right from (i, j)
        // jump[i][j][1] -> landing if moving down from (i, j)
        std::vector<std::vector<std::vector<std::pair<int, int>>>> jump(
            m, std::vector<std::vector<std::pair<int, int>>>(n, std::vector<std::pair<int, int>>(2, {-1, -1}))
        );

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                jump[i][j][0] = get_landing(i, j, 0, 1); // Move right
                jump[i][j][1] = get_landing(i, j, 1, 0); // Move down
            }
        }

        std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                // Try moving right
                auto [nr, nc] = jump[i][j][0];
                if (nr != -1 && nc != -1) {
                    dp[nr][nc] = (dp[nr][nc] + dp[i][j]) % MOD;
                }

                // Try moving down
                auto [nd_r, nd_c] = jump[i][j][1];
                if (nd_r != -1 && nd_c != -1) {
                    dp[nd_r][nd_c] = (dp[nd_r][nd_c] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};