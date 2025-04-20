class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true; // 都为空，对称
        if (!t1 || !t2) return false; // 一个为空，一个不为空，不对称
        if (t1->val != t2->val) return false; // 值不相等，不对称

        // 比较外侧和内侧
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};
