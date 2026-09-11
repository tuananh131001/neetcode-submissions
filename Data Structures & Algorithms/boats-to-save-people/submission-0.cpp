class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // [1,2,4,5]
        // if sum >= limit -> move right and increase length
        // else move left
        // 1 + 5 = limit 
        // 1 + 4 -> move left
        // 2 + 4 -> move right and increase lenght
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int res = 0;
        while (l < r) {
            int sum = people[l] + people[r];
            if (sum >= limit) {
                res += 1;
                r--;
            } else {
                l++;
            }
        }
        return res;
    }
};