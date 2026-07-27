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
    // Hash map to find the index of a value in the inorder traversal quickly
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        // Base case: if there are no elements to construct the subtree
        if (left > right) return nullptr;

        // Select the preorderIndex element as the root and increment it
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Build left and right subtrees based on the root's index in inorder array
        int inorderIndex = inorderMap[rootValue];

        // Elements to the left of inorderIndex go to the left subtree
        root->left = arrayToTree(preorder, left, inorderIndex - 1);
        
        // Elements to the right of inorderIndex go to the right subtree
        root->right = arrayToTree(preorder, inorderIndex + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorderMap.clear();
        preorderIndex = 0;

        // Build the hash map
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        return arrayToTree(preorder, 0, inorder.size() - 1);
    }
};

