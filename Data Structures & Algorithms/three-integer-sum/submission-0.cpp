class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int num : nums) {
            int l = 0;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = (nums[l] + nums[r]);
                if (sum == num) {
                    res.push_back(vector{num, nums[l], nums[r]});
                } else if (sum < num) {
                    r--;
                } else if (sum > num) {
                    l++;
                }
            }
        }
        return res;
    }
};
