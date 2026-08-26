class Solution {
public:
    std::string shortestBeautifulSubstring(std::string s, int k) {
        std::vector<int> ones;
        
        // Step 1: Collect all indices where '1' appears
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }
        
        // If there are fewer than k '1's, no beautiful substring exists
        if (ones.size() < k) {
            return "";
        }
        
        std::string ans = "";
        int min_len = s.length() + 1;
        
        // Step 2: Check every window of k '1's
        for (int i = 0; i <= ones.size() - k; ++i) {
            int left = ones[i];
            int right = ones[i + k - 1];
            std::string sub = s.substr(left, right - left + 1);
            
            // Step 3: Compare lengths and lexicographical order
            if (sub.length() < min_len) {
                min_len = sub.length();
                ans = sub;
            } else if (sub.length() == min_len) {
                if (ans == "" || sub < ans) {
                    ans = sub;
                }
            }
        }
        
        return ans;
    }
};