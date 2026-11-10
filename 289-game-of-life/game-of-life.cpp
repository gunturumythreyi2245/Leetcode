#include <vector>
#include <algorithm>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = 0;
                
                for (int x = std::max(0, i - 1); x < std::min(m, i + 2); ++x) {
                    for (int y = std::max(0, j - 1); y < std::min(n, j + 2); ++y) {
                        liveNeighbors += board[x][y] & 1;
                    }
                }
                
                liveNeighbors -= board[i][j] & 1;
                
                if ((board[i][j] & 1) == 1) {
                    if (liveNeighbors == 2 || liveNeighbors == 3) {
                        board[i][j] |= 2;
                    }
                } else {
                    if (liveNeighbors == 3) {
                        board[i][j] |= 2;
                    }
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
