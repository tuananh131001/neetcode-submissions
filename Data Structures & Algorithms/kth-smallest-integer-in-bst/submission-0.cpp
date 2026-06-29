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
public:
    int kthSmallest(TreeNode* root, int k) {
        int cmt = 0;
        int result = 0;
        dfs(root, cmt, k, result);
        return result;
    }

    void dfs(TreeNode* root, int& cmt, int k, int& result) {
        // base case, not node or count is large than k then return stack
        if (!root || cmt >= k) {
            return;
        }

        dfs(root->left, cmt, k, result);
        // when found the kth smallest
        cmt++;
        if (cmt == k) {
            result = root->val;
            return;
        }
        
        return dfs(root->right, cmt, k, result);
    }
};
