class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res(nums.size()-k+1);

        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            // if the curr. nums larger than the num in deque
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r);

            if (l > q.front()) {
                q.pop_front();
            }

            // check the windows is expand
            if ( (r + 1) >= k) {
                res[l] = nums[q.front()];
                l++;
            }

            r++;
        }

        return res;
    }
};
