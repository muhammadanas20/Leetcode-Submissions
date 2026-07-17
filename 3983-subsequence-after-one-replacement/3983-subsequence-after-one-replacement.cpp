class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
       int m = s.length();
        int n = t.length();
        
        if (m > n) return false;

        // pref[i] stores the earliest index in t that can finish matching s[0...i]
        std::vector<int> pref(m, n);
        int t_idx = 0;
        for (int i = 0; i < m; ++i) {
            while (t_idx < n && t[t_idx] != s[i]) {
                t_idx++;
            }
            if (t_idx < n) {
                pref[i] = t_idx;
                t_idx++; // move to next for subsequent matches
            } else {
                break; // remaining characters of s cannot be matched
            }
        }

        // If the entire string s is already a subsequence
        if (pref[m - 1] < n) return true;

        // suff[i] stores the latest index in t that can start matching s[i...m-1]
        std::vector<int> suff(m, -1);
        t_idx = n - 1;
        for (int i = m - 1; i >= 0; --i) {
            while (t_idx >= 0 && t[t_idx] != s[i]) {
                t_idx--;
            }
            if (t_idx >= 0) {
                suff[i] = t_idx;
                t_idx--;
            } else {
                break;
            }
        }

        // Check if we can change exactly one character at index i
        for (int i = 0; i < m; ++i) {
            int left_bound = (i == 0) ? -1 : pref[i - 1];
            int right_bound = (i == m - 1) ? n : suff[i + 1];

            // If the prefix before i and suffix after i are both validly matchable
            if (left_bound < n && right_bound > -1) {
                // There must be at least 1 character available in t between them
                if (right_bound - left_bound >= 2) {
                    return true;
                }
            }
        }

        return false;
    }
};