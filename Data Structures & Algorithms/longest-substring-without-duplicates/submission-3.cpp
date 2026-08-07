class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_map<char, int> m;
        for (int r = 0; r < s.size(); r++) {
            if (m.find(s[r]) != m.end()) {
                l = m[s[r]] + 1;
                m[s[r]] = r;
            } {
                m.insert({s[r], r});
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};
