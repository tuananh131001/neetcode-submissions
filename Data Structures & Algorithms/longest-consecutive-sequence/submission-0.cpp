class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s = unordered_set(nums.begin(), nums.end());
        int length = 1;
        int res = 0;
        for (int num: s) {
            if (s.find(num - 1) != s.end()) { // found the value
                int start = num - 1;
                while (s.find(start + length) != s.end()) {
                    length++;
                }
            }
            res = max(res, length);
        }
        return res;
        
    }
};
