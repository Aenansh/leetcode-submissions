class NumberContainers {
    map<int, int> cont;
    unordered_map<int, set<int>> ind;

public:
    NumberContainers() {}

    void change(int index, int number) {
        if (cont.count(index)) {
            int prevnum = cont[index];
            ind[prevnum].erase(index);
        }
        cont[index] = number;
        ind[number].insert(index);
    }

    int find(int number) { 
        if(!ind[number].empty()) return *(ind[number].begin());
        return -1;
        }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
