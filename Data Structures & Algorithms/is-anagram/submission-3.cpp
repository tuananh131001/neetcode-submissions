class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> charS;
        unordered_map<char, int> charT;

        for (int i = 0; i < s.size(); i++){
            charS[s[i]]++;
            charT[t[i]]++;
        }
        return charS == charT;
        
    }
};
