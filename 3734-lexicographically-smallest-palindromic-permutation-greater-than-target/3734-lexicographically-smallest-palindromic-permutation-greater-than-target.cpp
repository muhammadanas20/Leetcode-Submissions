#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
            count[i] /= 2; 
        }

        if (odd_count > 1) return "";

        int half_len = n / 2;
        string left_half = "";
        
        if (!dfs(0, half_len, count, target, false, left_half, mid_char, n)) {
            return "";
        }

        string full_palindrome = left_half;
        if (n % 2 != 0) {
            full_palindrome += mid_char;
        }
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        full_palindrome += right_half;

        return full_palindrome;
    }

private:
    bool dfs(int idx, int half_len, vector<int>& count, const string& target, 
             bool is_greater, string& current, char mid_char, int n) {
        
        if (idx == half_len) {
            if (is_greater) return true;
            
            // If prefix matches exactly, construct the rest mentally to check
            string tail = "";
            if (n % 2 != 0) tail += mid_char;
            string rev = current;
            reverse(rev.begin(), rev.end());
            tail += rev;
            
            return tail > target.substr(half_len);
        }

        char min_char = is_greater ? 'a' : target[idx];

        for (char c = min_char; c <= 'z'; ++c) {
            int char_idx = c - 'a';
            if (count[char_idx] > 0) {
                count[char_idx]--;
                current.push_back(c);

                bool next_greater = is_greater || (c > target[idx]);
                if (dfs(idx + 1, half_len, count, target, next_greater, current, mid_char, n)) {
                    return true;
                }

                current.pop_back();
                count[char_idx]++;
            }
        }
        return false;
    }
};
