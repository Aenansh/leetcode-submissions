class LRUCache {
    int cap;
    list<int> cache;
    unordered_map<int, pair<list<int>::iterator, int>> mp;

    void makeRecent(int key) {
        cache.erase(mp[key].first);
        cache.push_front(key);

        mp[key].first = cache.begin();
    }
public:
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        int res = mp[key].second;
        makeRecent(key);
        return res;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            makeRecent(key);
            return;
        }

        cache.push_front(key);
        mp[key] = {cache.begin(), value};

        if (mp.size() > cap) {
            int k = cache.back();
            cache.pop_back();
            mp.erase(k);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
