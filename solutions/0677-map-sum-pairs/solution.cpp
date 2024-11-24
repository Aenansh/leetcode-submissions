class MapSum {
    unordered_map<string, int> map;
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        map[key] = val;
    }
    
    int sum(string prefix) {
        int s = 0;
        for(auto i : map)
        {
            if(prefix == i.first.substr(0, prefix.length()))
            {
                s += i.second;
            }
        }
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
