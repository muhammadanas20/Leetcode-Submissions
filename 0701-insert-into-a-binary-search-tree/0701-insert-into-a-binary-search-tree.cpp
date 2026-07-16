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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val); //found where to insert
         // in BST left side is smaller than root so is val is smaller then insert to left otherise right recursively
        if(val < root->val) root->left = insertIntoBST(root->left,val);
        else root->right = insertIntoBST(root->right,val);

        return root;
    }
};