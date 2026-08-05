class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            long long hours = 0;
            for (int pile : piles) {
                hours += ceil( static_cast<double>(pile) / mid);
            }
            if (hours <= h) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
        
    }
};
