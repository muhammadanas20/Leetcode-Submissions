/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while(curr != nullptr){
            if(p->val > curr->val && q->val > curr->val){
                //both target has greater value so search right that BST
                curr = curr->right;
            }
            else if(p->val < curr->val && q->val < curr->val){
                //both target are smaller then search left side
                curr = curr->left;
            }
            else{
                //found the split where there val is is less or greater so two splits
                return curr;
            }
        }
        return nullptr;
    }
};