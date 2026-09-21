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
            int mul = 1;
            for (int j = i - 1; j >= 0; j--) {
                mul *= nums[j];
            }
            prefix[i] = mul;
        }

        // Back ward
        for (int i = nums.size() - 2; i >= 0; i--) { // i = 1
            int mul = 1;
            for (int j = i + 1; j <= nums.size() - 1; j++) { // j = 2
                mul *= nums[j];
            }
            suffix[i] = mul;
        }
        // Calculate 
        for (int i = 0; i <= n - 1; i++ ) {
            res[i] = prefix[i] * suffix[i];
        }
        return res;
    }
};
