class Solution {
public:
    bool canJump(vector<int>& nums) {
        // rule: 
        // steps = nums[i]
        // while ( i < length )
             
        //  i += nums[i]
        // 

        /*
        [1, 0]
        start 1
        step 1 
        if length and nums[i] is 0


        [1, 0, 0] -> false
        start 1 
        step 1
        if i at end and nums[i] is 0

        [1, 2, 0]


        */
        int curr_idx = 0;

        while(curr_idx <= nums.size() - 1) {
            if (nums[curr_idx] == 0 && curr_idx == nums.size() - 1) {
                return true;
            }
            // if cannot jump and not reach the the end of arr means break return false
            if ( nums[curr_idx] == 0 && curr_idx < nums.size() - 1 ) {
                return false;
            }
            curr_idx += nums[curr_idx]; // jump by steps
        }
        return true;
        
    }
};
