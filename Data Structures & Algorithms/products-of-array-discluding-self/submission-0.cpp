class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> tempNum(nums);
            tempNum.erase(tempNum.begin() + i);
            hash.insert({nums[i], tempNum});
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int multiply = 1;
            for (int num : hash[nums[i]]) {
                multiply *= num;
            }
            res.push_back(multiply);
        }
        return res;
    }
};
