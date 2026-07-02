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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // create an array to hold the path
        // create helper function to do backtrack
        // result
        int sum = 0;
        bool result = false;
        backtrack(root, sum, targetSum, result);
        return result;
    }

    // function backtrack (root, paths, target, res)
    // if 

    // if empty both left and right child
    //

    // backtrack by poping the path

    void backtrack(TreeNode* node, int sum, int target, bool& result) {
        if (!node) {
            return;
        }

        sum += node->val; // increase total 
        cout << "Sum: " << sum << "\n";
        cout << "Current node is " << node->val << "\n";

        if (!node->left && !node->right) { // checkif this is an leaf node
            if (target == sum) {
                cout << "When at leaf node the sum is: " << sum<< "\n";
                result = true;
            }
        } else {
            backtrack(node->left, sum, target, result); // normal dfs left traversal
            backtrack(node->right, sum, target, result); // normal dfs right traversal
        }
    }
};