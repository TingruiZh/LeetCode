class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 如果都为空，说明是一样的
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // 如果只有一个为空 或者值不相等，说明不一样
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }
        // 递归比较左右子树
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
