class ProductOfNumbers {
    vector<int> stream;
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        stream.push_back(num);
    }
    
    int getProduct(int k) {
        if(stream.size() < k) return 0;
        int ans = 1;
        int i = stream.size() - 1;
        while(k > 0){
            ans *= stream[i];
            i--;
            k--;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
