class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted_strs = strs;
        for (string& str: sorted_strs) {
            sort(str.begin(), str.end());
        }

        unordered_map<string,vector<string>> hash;
        for (int i; i < strs.size(); ++i) {
            if (!hash.contains(sorted_strs[i])) { // check if sorted string not in hash
                cout << "Not found key " << sorted_strs[i] << "\n";
                hash[sorted_strs[i]] = {strs[i]}; // add to sorted string key with value of vector of unsorted str
            } else { // if sorted str in hash
                // get the hash value by sorted str key
                // push back the unsorted str to value
                // update the hash value of the key with new vector
                cout << "Found same key "<< sorted_strs[i] << "\n";

                vector<string> values = hash[sorted_strs[i]];
                values.push_back(strs[i]);
                cout << strs[i];
                hash[sorted_strs[i]] = values; 
            }
        }
        vector<vector<string>> res;
        for (const auto& [key, value] : hash) {
            res.push_back(value);
        }
        return res;
    }
};
