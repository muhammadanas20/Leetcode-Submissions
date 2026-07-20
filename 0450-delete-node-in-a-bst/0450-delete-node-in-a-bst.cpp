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
    TreeNode* findmin(TreeNode* root){
        while(root && root->left) root = root->left;
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if(key < root->val) root->left = deleteNode(root->left,key); // BST: left < root < right
        else if( key > root->val) root->right = deleteNode(root->right,key);
        else{
            //found key == root->val

            // case 1
            if(!root->left && !root->right) {
             delete root; 
             return nullptr;
            }
            //case 2
            // if any one child
            else if(!root->left || !root->right){
                TreeNode* temp;
                if(root->left) temp = root->left;
                else temp = root->right;
                delete root;
                return temp;
            }

            //case 3 
            //two child so we need to find inorder sucessor of right subtree
            // min val of right that still greater than current so replace it and then delete duplicate
            TreeNode* sucessor = findmin(root->right);
            root->val  = sucessor->val;  //replace val
            root->right = deleteNode(root->right,sucessor->val); // delete that duplicate Node and retrun to right to add           
        }
        return root;
    }
};