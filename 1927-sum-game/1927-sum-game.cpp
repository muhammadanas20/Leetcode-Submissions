class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        double balance = 0.0;
        
        // Process the first half (adds to balance)
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') balance += 4.5;
            else balance += (num[i] - '0');
        }
        
        // Process the second half (subtracts from balance)
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') balance -= 4.5;
            else balance -= (num[i] - '0');
        }
        
        // If balance is 0, Bob can force a tie (Bob wins -> false)
        // Otherwise, Alice can force a mismatch (Alice wins -> true)
        return balance != 0.0;
    }
};
