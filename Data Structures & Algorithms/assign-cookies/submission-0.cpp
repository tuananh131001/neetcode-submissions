class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        vector<int> cookies = s;
        sort(g.begin(), g.end());
        sort(cookies.begin(), cookies.end());

        int i = 0; // greeds
        int j = 0; // cookies
        int count = 0;
        while (i < g.size() && j < cookies.size()) {
            if (cookies[j] >= g[i]) { // cookies can satisfied the greed
                i++; // move to next greeds
                count++; // count the greeds have statisfied
            }
            j++; // move to next cookies 
        }
        return count;
    }
};