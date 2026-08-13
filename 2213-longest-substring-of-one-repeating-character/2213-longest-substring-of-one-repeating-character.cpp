// #include <vector>
// #include <string>
// #include <algorithm>
// #include <iostream>

// using namespace std;

class Solution {
    struct Node {
        int maxLen;      // Longest repeating substring in this range
        int prefixLen;   // Length of repeating prefix
        int suffixLen;   // Length of repeating suffix
        char leftChar;   // Character at the start of this range
        char rightChar;  // Character at the end of this range
        int len;         // Total length of this range (r - l + 1)
    };

    vector<Node> tree;
    string s;
    int n;

    // Merge two child nodes into a parent node
    Node merge(const Node& left, const Node& right) {
        Node parent;
        parent.len = left.len + right.len;
        parent.leftChar = left.leftChar;
        parent.rightChar = right.rightChar;

        // Base max length is the max of either child
        parent.maxLen = max(left.maxLen, right.maxLen);

        // Calculate new prefix length
        parent.prefixLen = left.prefixLen;
        if (left.prefixLen == left.len && left.rightChar == right.leftChar) {
            parent.prefixLen += right.prefixLen;
        }

        // Calculate new suffix length
        parent.suffixLen = right.suffixLen;
        if (right.suffixLen == right.len && right.leftChar == left.rightChar) {
            parent.suffixLen += left.suffixLen;
        }

        // Check if we can merge across the midpoint
        if (left.rightChar == right.leftChar) {
            parent.maxLen = max(parent.maxLen, left.suffixLen + right.prefixLen);
        }

        return parent;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {1, 1, 1, val, val, 1};
            s[idx] = val; // Optional: update the string itself if needed later
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        this->n = s.length();
        tree.resize(4 * n);
        
        build(1, 0, n - 1);
        
        vector<int> result;
        int k = queryCharacters.length();
        result.reserve(k); // Optimization to avoid reallocations

        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            result.push_back(tree[1].maxLen);
        }
        
        return result;
    }
};
