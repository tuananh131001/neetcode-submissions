class Solution {
public:
    bool isAnagram(string s, string t) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
