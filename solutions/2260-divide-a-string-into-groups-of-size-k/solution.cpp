class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        float diff = (float)(s.length()) / (float)(k);
        int size = ceil(diff), i = 0;
        vector<string> res;
        for(; i < diff - 1; i += 1) {
            string sub= "";
            for(int j = 0; j < k; j++) {
                sub += s[i*k + j];
            }
            res.push_back(sub);
        }
        i *= k;
        string last = "";
        for(; i < s.size(); i++) {
            last += s[i];
        }
        int fill_size = (size * k) - s.size();
        for(int i = 0; i < fill_size; i++) {
            last += fill;
        }
        res.push_back(last);
        return res;
    }
};
