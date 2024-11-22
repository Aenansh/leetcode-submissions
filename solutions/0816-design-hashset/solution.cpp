class MyHashSet {
    vector<int> set;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        for(int i = 0; i < set.size(); i++)
        {
            if(set[i] == key)
            return;
        }
        set.push_back(key);
    }
    
    void remove(int key) {
        for(int i = 0; i < set.size(); i++)
        {
            if(set[i] == key)
            {
                set.erase(set.begin() + i);
                break;
            }
        }
        return;
    }
    
    bool contains(int key) {
        for(int i = 0; i < set.size(); i++)
        {
            if(set[i] == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
