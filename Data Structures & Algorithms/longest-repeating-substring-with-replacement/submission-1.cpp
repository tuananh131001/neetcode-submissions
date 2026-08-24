class Solution {
public:
    int characterReplacement(string s, int k) {
       int l = 0;
       int freq[26] = {};
       int res = 0;
       int maxFreq = 0;
       for (int r = 0; r < s.size(); r++) {
            // Increase Freq of char in freq array
            int freqIdx = s[r] - 'A';
            freq[freqIdx]++;
            maxFreq = max(maxFreq, freq[freqIdx]);

            if ((r - l + 1) - maxFreq > k) { // mistake if make an reuseable value when l++ the res will calculate the old length
                freq[s[l] - 'A']--;
                l++;
            }
            // if the num of windows - freq < k 
                // move the l to shirk windows
                //  descride the freq of that num
            res = max(res, r - l + 1);
       } 
       return res;
    }
};
