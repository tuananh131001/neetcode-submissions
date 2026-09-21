class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int space = 0;
        while (l <= r) {
            int rem = limit - people[r];
            if (people[l] <= rem) {
                l++;
                r--;
            } else {
                r--;
            }
            space++;
        }
        return space;

    }
};