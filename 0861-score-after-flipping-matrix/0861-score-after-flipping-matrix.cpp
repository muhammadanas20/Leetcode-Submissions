#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // The first column will always be optimized to all 1s
        int score = m * (1 << (n - 1));
        
        // Optimize each column from index 1 to n-1
        for (int j = 1; j < n; ++j) {
            int count_ones = 0;
            for (int i = 0; i < m; ++i) {
                // If grid[i][0] is 0, the row will be flipped.
                // So grid[i][j] effectively becomes (grid[i][j] == grid[i][0])
                if (grid[i][j] == grid[i][0]) {
                    count_ones++;
                }
            }
            // Take the maximum of ones or zeros (flipped)
            int max_ones = std::max(count_ones, m - count_ones);
            score += max_ones * (1 << (n - j - 1));
        }
        
        return score;
    }
};
