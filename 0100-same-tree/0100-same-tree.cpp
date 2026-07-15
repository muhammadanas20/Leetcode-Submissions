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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if both left right is end 
        if(!p && !q) return true;
        
        //if either left or right is end not both or also if val is not same
        if(!p || !q || p->val != q->val) return false;
        
        //checking recursively for both left and right
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};