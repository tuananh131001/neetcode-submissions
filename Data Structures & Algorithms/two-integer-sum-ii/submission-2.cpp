class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        int sum = numbers[l] + numbers[r];
        while(sum != target) {
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            }
            sum = numbers[l] + numbers[r];
        }
        return vector<int>{l + 1,r + 1};
    }
};
