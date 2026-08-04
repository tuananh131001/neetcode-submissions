class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_map<char, int> m;
        for (int r = 0; r < s.size(); r++) {
            if (m.find(s[r]) != m.end()) {
                l = max(m[s[r]] + 1, l);
            }
            m[s[r]] = r;

            res = max(res, r - l + 1);
        }
        return res;
    }
};
