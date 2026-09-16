class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;

        unordered_map<char ,int> s1Dict; // Freq of s1
        unordered_map<char, int> windowDict; // Freq of window

        for (int i = 0; i < n; i++) { // n = 2
            s1Dict[s1[i]]++; // add freq for s1 char [{a, 1}, {b, 1}]
            windowDict[s2[i]]++; // add freq for windows char [{l, 1}, { e, 2}]
        }

        if (s1Dict == windowDict) return true;

        for (int i = n; i < m; i++) {// n = 2
            windowDict[s2[i]]++; // expand Windows by increase freq when window expand
            windowDict.erase(s2[i - n]); // shirk the window by decrase the freq of old value
            if (s1Dict == windowDict) return true;
        }

        return false;
    }
};
