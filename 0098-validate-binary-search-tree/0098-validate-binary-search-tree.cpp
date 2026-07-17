/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // Helper function to validate nodes against upper and lower limits
    bool isValid(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) {
            return true;
        }

        // Check if the current node value violates the allowed boundary
        if (root->val <= minVal || root->val >= maxVal) {
            // A node must be strictly greater than minVal and strictly less than maxVal
            return false;
        }

        // Left child must stay under the current node's value
        // Right child must stay above the current node's value
        return isValid(root->left, minVal, root->val) && 
               isValid(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        // Initialize the boundaries with the minimum and maximum possible long long values
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};
