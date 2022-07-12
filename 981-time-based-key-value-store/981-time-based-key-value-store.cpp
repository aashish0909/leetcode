class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key))
            return "";
        
        int left = 0, right = mp[key].size();
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(mp[key][mid].first > timestamp)
                right = mid;
            else left = mid + 1;
        }
        
        return (left > 0 and left <= mp[key].size() ? mp[key][left-1].second : "");
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */