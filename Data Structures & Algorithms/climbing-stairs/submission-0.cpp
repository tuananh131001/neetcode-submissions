class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> cache;
        return helper(n, cache);
    }
    int helper(int n, unordered_map<int, int>& cache) {
        //base case
        if (n <= 1) {
            return 1;
        }

        if (cache.find(n) != cache.end()) { // why cache.end()
            return cache[n];
        }

        cache[n] = helper(n-2, cache) + helper(n-1, cache);
        return cache[n];
    }
};
