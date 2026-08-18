class Solution {
public:
    int search(vector<int>& nums, int target) {
       int l = 0;
       int r = nums.size() - 1;
       while (l <= r) {
         int mid = l + (r - l) / 2;

         if (nums[mid] == target) return mid;

         // check if left halves is sorted?
         if (nums[l] <= nums[mid]) {
            // check if target is in left halves sorted
            if (target >= nums[l] && target < nums[mid]) {
                // move r to (left, mid - 1]
                r = mid - 1;
            } else {
                l = mid + 1;
            }
         } else {
            // if target <= 
            if (target <= nums[r] & target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
         }
       }
       return -1;

    }
};
