class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (string str: strs) {
            res += to_string(str.size());
            res += ',';
        }

        res += '#';

        for (string str: strs) {
            res += str;
        }
        cout << "encode: " << res << endl;

        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<int> sizes;
        while (s[i] != '#') {
            int j = i;
            while (s[j] != ',') {
                j++;
            }
            sizes.push_back(stoi(s.substr(i, j - i))); // push the size number
            i = j + 1;
        }
        i++;
        vector<string> res;
        for (int size: sizes) {
            cout << "size: " << size << endl;
            cout << "i " << i << endl;
            res.push_back(s.substr(i, size));
            i += size;
        }
        return res;

    }
};
