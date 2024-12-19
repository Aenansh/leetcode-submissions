class SmallestInfiniteSet {
    map<int, int> pnums;
public:
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++){
            pnums[i]++;
        }
    }
    
    int popSmallest() {
        int small = pnums.begin()->first;
        pnums.erase(pnums.begin());
        return small;
    }
    
    void addBack(int num) {
        if(!pnums[num])
        pnums[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
