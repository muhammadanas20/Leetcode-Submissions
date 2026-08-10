class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] stores if the player whose turn it is can win with i stones
        std::vector<bool> dp(n + 1, false);
        
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                // If the next player faces a losing state, the current player wins
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // Move to the next stone count early
                }
            }
        }
        
        return dp[n];
    }
};