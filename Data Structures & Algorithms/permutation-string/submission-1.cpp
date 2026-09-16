class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Set([eba]), count = 4 
        // l -> l = 0, r = 0
        // e -> found start win , l = 0, r= 1
        // ec -> not , reset , l = 2, r = 2
        // a -> yes , l = 2,r= 3
        // ab -> yes , l = 2, r = 4
        // abe -> yes count = 3 , l = 2, r = 5
        // abee -> yes count = 4 if count == count return  , l = 2, r = 6
        set<char> st(s1.begin(), s1.end());
        int count = s1.size();
        cout << "Count: " << count << endl;
        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            if ((r - l) == count && st.find(s2[r]) != st.end()) {
                return true;
            }

            if (st.find(s2[r]) == st.end()) { // not found s2[r] in set
                l = r; // reset
            }
        }
        return false;

    }
};
