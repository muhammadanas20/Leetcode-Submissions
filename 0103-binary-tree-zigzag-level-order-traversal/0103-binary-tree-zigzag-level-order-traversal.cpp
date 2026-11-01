class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if(root == NULL)
            return res;

        queue<TreeNode*> q;

        int flag = 0;

        q.push(root);

        while(!q.empty()) {

            int size = q.size();

            vector<int> level;

            for(int i = 0; i < size; i++) {

                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if(temp->left != NULL)
                    q.push(temp->left);

                if(temp->right != NULL)
                    q.push(temp->right);
            }

            if(flag == 1)
                reverse(level.begin(), level.end());

            res.push_back(level);

            flag = !flag;
        }

        return res;
    }
};