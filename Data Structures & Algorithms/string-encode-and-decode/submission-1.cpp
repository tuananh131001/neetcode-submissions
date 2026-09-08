class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.size() == 0 ) return {};
        string tmp;
        for (string& str: strs) {
            tmp += to_string(str.size());
            tmp += ",";
        }
        tmp += '#';
        for (string& str: strs) {
            tmp += str;
        }
        cout << "tmp: " << tmp << endl;
        return tmp;
    }

    vector<string> decode(string s) {
        if (s.size() == 0) return {};
        vector<string> res;
        int i = 0;
        vector<int> szs;
        while (s[i] != '#') {
            int j = i;
            while (s[j] != ',') {
                j++;
            }
            szs.push_back(std::stoi(s.substr(i,j - i))); // j - i means size of the number
            i = j + 1;
        }
        i++;
        cout << s[i] << endl;
        for (int size : szs) {
            res.push_back(s.substr(i, size));
            i += size;
        }
        cout << "encode: " << res[0] << endl;
        return res;
    }
};
