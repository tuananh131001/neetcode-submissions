class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // how to detect if the num is the begging of starting sequence
        // use hashset and check if the num - 1 is already in the set then start an while loop to calc
        unordered_set<int> pastSet(nums.begin(), nums.end());
        int res = 0;

        for (int num: nums) { // num = 3 , num = 5
            if (pastSet.find(num - 1) != pastSet.end()) { // found // found num = 2, num = 5 is in set
                int length = 1;
                while (pastSet.find(num  - 1 + length) != pastSet.end()) // continue loop bit start from the num which start the sequece . My error is start from the current num which not the start of sequence so the length max is not the length of the sequence
                    length++;
                res = max(length, res); // res = 4
            }
        }
        return res;
    }
};
