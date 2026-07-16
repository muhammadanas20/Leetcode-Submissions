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
    int dfs(TreeNode* root,int max_so_far){
        if(!root) return 0;

        int is_good = (root->val >= max_so_far) ? 1 : 0;
         max_so_far = max(max_so_far,root->val);
        int left = dfs(root->left,max_so_far);
        int right = dfs(root->right,max_so_far);

        return is_good + left + right;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};