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
    bool isSameTree(TreeNode* a,TreeNode* b){
        if(!a && !b) return true;

        if(!a || !b || a->val != b->val) return false;

        return isSameTree(a->left,b->left) && isSameTree(a->right,b->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //if subroot ends then its a part of root
        if(!subRoot) return true;
       //if root ends but not subroot so its false
        if(!root) return false;
        //if root and subtree is same then true and if not it wil not run root move to another node
        if(isSameTree(root,subRoot)) return true;
         //traverse left and right if found then true
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};