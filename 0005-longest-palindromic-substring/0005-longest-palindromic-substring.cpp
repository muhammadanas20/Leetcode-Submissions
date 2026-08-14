class Solution {
private:
    // Helper function to expand outward and return the length of the palindrome
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Returns the length of the palindrome found
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, max_length = 0;

        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd-length palindromes (e.g., "aba", center is 'b')
            int len1 = expandAroundCenter(s, i, i);
            
            // Case 2: Even-length palindromes (e.g., "abba", center is between 'b' and 'b')
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > max_length) {
                max_length = len;
                // Calculate the starting index of this substring
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, max_length);
    }
};
