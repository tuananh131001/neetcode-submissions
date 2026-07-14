class Solution {
private:
    vector<vector<int>> res;
    vector<int> nums;
    void backtrack(int idx, vector<int>& paths) {
        if (idx == nums.size()) {
            res.push_back(paths);
            return;
        }

        // include
        paths.push_back(this->nums[idx]);
        backtrack(idx + 1, paths);
        paths.pop_back(); // backtrack

        // exclude
        backtrack(idx + 1, paths);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        vector<int> paths;
        backtrack(0, paths);
        return this->res;
    }



    
};
