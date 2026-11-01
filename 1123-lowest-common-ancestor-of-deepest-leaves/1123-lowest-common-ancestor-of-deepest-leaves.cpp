
class Solution {
public:

    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        if (root == NULL)
            return NULL;

        int left = height(root->left);
        int right = height(root->right);

        if (left == right)
            return root;

        if (left > right)
            return lcaDeepestLeaves(root->left);

        return lcaDeepestLeaves(root->right);
    }
};
