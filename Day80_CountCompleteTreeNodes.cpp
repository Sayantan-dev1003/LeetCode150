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
public:
    int computeHeight(TreeNode* node, bool leftPath) {
        int height = 0;
        while (node) {
            height++;
            node = leftPath ? node->left : node->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        int leftHeight = computeHeight(root, true);
        int rightHeight = computeHeight(root, false);

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
