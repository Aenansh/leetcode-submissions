class CustomStack {
    vector<int> s;
    int size;
public:
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(s.size() == size) return;
        s.push_back(x);
    }
    
    int pop() {
        if(s.empty()) return -1;
        int i = s.back();
        s.pop_back();
        return i;
    }
    
    void increment(int k, int val) {
        if(s.empty()) return;
        if(k >= s.size())
        {
            for(int i = 0; i < s.size(); i++)
            {
                s[i] += val;
            }
        }
        else{
            for(int i = 0; i < k; i++)
            {
                s[i] += val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
