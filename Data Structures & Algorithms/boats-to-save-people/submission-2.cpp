class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // [1,2,4,5]
        // if sum >= limit -> move right and increase length
        // else move left
        // 1 + 5 = limit 
        // 1 + 4 -> move left
        // 2 + 4 -> move right and increase lenght

        // [3,5,3,4]
        // first boat: [4]
        // second boat: [3]
        // three boat: [5]
        // fource: [3]
        // possible pattern in two pointer
        // 1. Left and Right pointer
        // 2. Fast and slow pointer
        // combine those method with hash, set, stack, queue?
        // init an slow and fast pointer
        // fast pointer will check if the next number of people is fit to an boat else increase the length

        // [1,2,4,5]
        //  1, 5 -> move both , boat ++ 
        //  2,4 -> move both, boat++

        // [3,5,3,4]
        // ->[3,3,4,5]
        // 3,5 > limit -> right move, boat++
        // 3,4 > limit -> right move, boat++
        // 3,3 > limit -> right move ,boat++
        /// 3,3 > limit -> right move , boat++


        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int res = 0;
        while (l <= r) {
            int sum = people[l] + people[r];
            if (sum <= limit) {
                l++;
                r--;
            } else {
                r--;
            }
            res++;
        }
        return res;
    }
};