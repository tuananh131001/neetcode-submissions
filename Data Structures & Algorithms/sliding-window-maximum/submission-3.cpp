class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //create an slidling windows with size of k
        // create an array of result

        int left_win = 0;
        int right_win = left_win + k;
        vector<int> res;

        while (right_win < nums.size() + 1) { // size: 7
            priority_queue<int> q;
            for (int i = left_win; i <= right_win - 1 ; i++) { // i = 0 right_win = 3, 
                if (q.size() < k) { // 
                    q.push(nums[i]);
                } else if (nums[i] > q.top()) {
                    q.pop();
                    q.push(nums[i]);
                }
            }
            int numPop = q.top();
            q.pop();
            res.push_back(numPop);

            left_win++;
            right_win++;
        }
        return res;
    }
};
