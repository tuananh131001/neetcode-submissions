class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        vector<int> prefix{1};
        vector<int> suffix{1};

        // Forward
        for (int i = 1; i < nums.size(); i++) { // i = 2
            int mul = 1;
            for (int j = i - 1; j >= 0; j--) {
                mul *= nums[j];
            }
            prefix.push_back(mul);
        }

        // Back ward
        for (int i = nums.size() - 2; i >= 0; i--) { // i = 1
            int mul = 1;
            for (int j = i + 1; j <= nums.size() - 1; j++) { // j = 2
                mul *= nums[j];
            }
            suffix.insert(suffix.begin(), mul);
        }
        // Calculate 
        for (int i = 0; i <= nums.size() - 1; i++ ) {
            res.push_back(prefix[i] * suffix[i]);
        }
        return res;
    }
};
