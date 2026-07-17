class Solution {
    vector<vector<int>> res;
    vector<int> nums;
private:
    void dfs(int idx, vector<int> paths, int sum, int target) {
        if (sum == target) {
            res.push_back(paths);
            return;
        }
        if (idx >= nums.size() || sum > target) {
            return;
        }

        paths.push_back(nums[idx]);
        dfs(idx, paths, sum + nums[idx], target);
        paths.pop_back(); // backtrack
        dfs(idx + 1, paths, sum, target); // sum keep the same before added
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->nums = nums;
        vector<int> paths;
        dfs(0, paths, 0, target);
        return this->res;
    }
};
