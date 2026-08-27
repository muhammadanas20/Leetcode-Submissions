#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        std::vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        // Helper function to check if remaining characters can form a string > suffix of target
        // We can try to build the prefix common with target, then pick a strictly larger char, then sort the rest.
        // Let's use a backtracking/greedy approach from right to left to find the last modified position.
        for (int i = n - 1; i >= 0; --i) {
            // Restore counts for characters after index i
            // Actually, a simpler way is to try increasing the character at index i.
            // Let's re-populate counts up to i-1.
            std::vector<int> cur_count = count;
            std::string prefix = "";
            bool possible = true;
            for (int j = 0; j < i; ++j) {
                if (cur_count[target[j] - 'a'] > 0) {
                    cur_count[target[j] - 'a']--;
                    prefix += target[j];
                } else {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;

            // At index i, we need a character strictly greater than target[i]
            for (int c_idx = target[i] - 'a' + 1; c_idx < 26; ++c_idx) {
                if (cur_count[c_idx] > 0) {
                    cur_count[c_idx]--;
                    std::string candidate = prefix + (char)('a' + c_idx);
                    
                    // Append the rest of the characters in sorted order for the smallest lexicographical result
                    for (int k = 0; k < 26; ++k) {
                        while (cur_count[k] > 0) {
                            candidate += (char)('a' + k);
                            cur_count[k]--;
                        }
                    }
                    return candidate;
                }
            }
        }
        return "";
    }
};
