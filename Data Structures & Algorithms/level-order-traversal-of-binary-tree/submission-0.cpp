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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<TreeNode*> firstArr = {root};
        vector<vector<int>> res;
        queue<vector<TreeNode*>> q;
        q.push(firstArr);
        while(!q.empty()){
            vector<TreeNode*> curr = q.front();
            q.pop();
            vector<int> nums;
            vector<TreeNode*> nodes;
            for (TreeNode* node: curr) {
                nums.push_back(node->val);
                if (node->left) {
                    nodes.push_back(node->left);
                } 
                if (node->right) {
                    nodes.push_back(node->right);
                }
            }
            if (!nodes.empty()) q.push(nodes);
            if (!nums.empty()) res.push_back(nums);
        }
        return res;
    }
};
