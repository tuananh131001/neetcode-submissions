class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i <= nums.size() - 2; i++) {
            int remain = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (remain == nums[j]) return vector<int>{i,j};
            }
        }
        return vector<int>{0,0};
    }
};
