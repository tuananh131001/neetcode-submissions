class Solution {
public:
    int search(vector<int>& nums, int target) {
        // if the left is sorted then find in the right
        // if the right is sorted then search in the left
        int l = 0;
        int r = nums.size() - 1;
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                res = mid;
                break;
            }
            if (nums[l] < nums[r]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
