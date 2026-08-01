class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;

        int l = 0;
        int r = k + l - 1;
        while (r < nums.size()) {
            int max = findMax(l, r, nums);
            q.push_back(max);
            l++;
            r++;
        }


        for (int num: q) {
            res.push_back(num);
        }
        return res;
    }
    int findMax(int start, int end, vector<int>& nums){
        int max = nums[start];
        for (int i = start; i <= end; i++) {
            if (nums[i] > max) max = nums[i];
        }
        return max;
    }
};
