class Solution {
public:
    int dfs(vector<int>& nums) {
        if (nums.size() == 2) {
            return 0;
        }
        int maxCoins = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            int coins = nums[i - 1] * nums[i] * nums[i + 1];
            vector<int> newNums = nums;
            newNums.erase(newNums.begin() + i);
            coins += dfs(newNums);
            maxCoins = max(coins, maxCoins);
        }
        return maxCoins;
    }


    int maxCoins(vector<int>& nums) {
        // use recursion  and decision tree first there are nth possible cases, each case calculate the coin then sum each cases
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return dfs(nums);
    }       
    
};
