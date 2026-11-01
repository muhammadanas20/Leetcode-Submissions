
class Solution {
public:

    pair<int, TreeNode*> solve(TreeNode* root) {

        if (root == NULL)
            return {0, NULL};

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.first > right.first)
            return {left.first + 1, left.second};

        if (right.first > left.first)
            return {right.first + 1, right.second};

        return {left.first + 1, root};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;
    }
};
