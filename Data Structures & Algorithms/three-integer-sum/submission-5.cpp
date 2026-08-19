class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i <= n - 3; i++ ) { // n - 3 to avoid collise with l and r
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip to avoid duplicate
            int l = i + 1;
            int r = n - 1;
            while (l < r) { // Cannot use equal due to each numbers cannot be use again
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l],nums[r]});
                    //move l and r
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    l++;
                    r--;
                } else if (sum > 0) { // move r to smaller the sum
                    r--;
                } else {
                    l++;
                }
            }
        }
        return res; 
    }
};
