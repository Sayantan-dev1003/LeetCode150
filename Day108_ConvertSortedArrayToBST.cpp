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
    TreeNode* buildBST(const vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = buildBST(nums, left, mid - 1);
        node->right = buildBST(nums, mid + 1, right);

        return node;
    }
    void printLevelOrder(TreeNode* root) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                cout << curr->val << " ";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};
