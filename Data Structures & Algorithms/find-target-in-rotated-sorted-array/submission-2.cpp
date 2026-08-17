class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target) return mid;

            // check if the left sub array is sorted
            if (nums[l] <= nums[mid]) {
                // if the target in left then search left
                if (target >= nums[l] && target < nums[mid]) {
                   r = mid - 1;
                } else {
                   l = mid + 1;
                }
            } else {
                // if the target in right then search right
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
        }
        return -1;
        
    }
};
