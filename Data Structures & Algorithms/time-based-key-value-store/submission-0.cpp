class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        // set an hash with vector by key and the vector is timestamp
        m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& tmp = m[key]; // array [<1, bar>, <4, bar2>]
        string val = "";
        int l = 0;
        int r = tmp.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            // check using first 
            if (tmp[mid].first <= timestamp) {
                val = tmp[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return val;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */