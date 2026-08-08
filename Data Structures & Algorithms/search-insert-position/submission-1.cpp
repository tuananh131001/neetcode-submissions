class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int res = ;
        for (l < r) {
            int mid = (r + l) / 2;

            if (nums[mid] == target) {
                return mid;
            }
        }
    }
};