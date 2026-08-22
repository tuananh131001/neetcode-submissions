class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int th = 0;
        int res = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) th++;
            while (th > k) {
                if (nums[l] == 0) th--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
        
    }
};