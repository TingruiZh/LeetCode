class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            level.reserve(sz);

            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (leftToRight) {
                    level.push_back(node->val);
                } else {
                    // 从右向左则插到前面
                    level.insert(level.begin(), node->val);
                }
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(std::move(level));
            leftToRight = !leftToRight;
        }

        return ans;
    }
};
