class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = 1;
        suffix[n - 1] = 1;

        // Forward
        for (int i = 1; i < n; i++) { // i = 2
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Back ward
        for (int i = nums.size() - 2; i >= 0; i--) { // i = 1
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        // Calculate 
        for (int i = 0; i <= n - 1; i++ ) {
            res[i] = prefix[i] * suffix[i];
        }
        return res;
    }
};
