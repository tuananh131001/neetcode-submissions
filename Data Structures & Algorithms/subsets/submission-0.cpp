class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(0 ,path, res, nums);
        return res;
    }
    void backtrack(int idx, vector<int>& path, vector<int>& res, vector<int>& nums) {
        if (nums.size() == idx) {
            path.push_back(path);
            return;
        }
        path.push(nums[idx]);
        backtrack(idx++, path, res, nums);
        path.pop_back();
        backtrack(idx--, path, res, nums);
    }
};
