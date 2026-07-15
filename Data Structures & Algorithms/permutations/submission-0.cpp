class Solution {
    vector<int> nums;
    vector<vector<int>> res;
private: 
    void backtrack(int idx, vector<int>& paths) {
        if (idx == nums.size()) {
            res.push_back(paths);
            return;
        }
        for(int num: nums) {
            // if the num not in paths
            if (find(paths.begin(), paths.end(), num) != paths.end()) {
                cout << "Num already in paths: " << num << "\n";
                continue;
            }

            // add num from num to path
            paths.push_back(num);
            backtrack(idx + 1, paths);
            // backtrack
            paths.pop_back();
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        vector<int> paths;
        backtrack(0, paths);
        return this->res;
    }
};
