/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int dfs(TreeNode* node, int& maxSum) {
        if (!node)
            return 0;

        int left = max(dfs(node->left, maxSum), 0);
        int right = max(dfs(node->right, maxSum), 0);

        int currentPath = node->val + left + right;

        maxSum = max(maxSum, currentPath);

        return node->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};
