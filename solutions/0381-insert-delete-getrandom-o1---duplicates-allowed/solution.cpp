class RandomizedCollection {
    vector<int> col;
    unordered_map<int, int> search;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        if(!search[val]){
            search[val]++;
            col.push_back(val);
            return true;
        }
        else{
            search[val]++;
            col.push_back(val);
            return false;
        }
    }
    
    bool remove(int val) {
        if(!search[val]) return false;
        else{
            search[val]--;
            auto it = find(col.begin(), col.end(), val);
            col.erase(it);
            return true;
        }
    }
    
    int getRandom() {
        return col[rand() % col.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
