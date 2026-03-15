class Fancy {
    vector<int> v;
    long add, mul;
    int mod;

public:
    Fancy() {
        add = 0, mul = 1;
        mod = 1e9 + 7;
    }
    long power(long a, long b) {
        if (b == 0)
            return 1;
        long half = power(a, b / 2);
        long res = (half * half) % mod;
        if (b % 2 == 1)
            res = (res * a) % mod;
        return res;
    }
    void append(int val) {
        long num = (val - add) % mod;
        if (num < 0)
            num += mod;
        num = (num * power(mul, mod - 2)) % mod;
        v.push_back(num);
    }

    void addAll(int inc) { add = (add + inc) % mod; }

    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= v.size())
            return -1;
        int num = v[idx];
        num = (num * mul) % mod;
        num = (num + add) % mod;
        return num;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
