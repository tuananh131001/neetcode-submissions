class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int thres = 0;
        int res = 0;
        int originChar = s[0];
        for (int r = 0; r < s.size(); r++) {
            if (s[r] != originChar) thres++;
            while (thres > k) {
                if (s[l] != originChar) {
                    thres--;
                }
                l++;

            }
            res = max(res, r - l + 1);
        }
        return res;
        
    }
};
