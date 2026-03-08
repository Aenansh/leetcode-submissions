class Solution {
public:
    int binaryToDecimal(string bin) {
        int res = 0;
        for(char& b : bin) {
            if(b == '0' && res == 0) continue;
            else if(b == '1' && res == 0) res = 1;
            else if(b == '1' && res != 0) res = res * 2 + 1;
            else if(b == '0' && res != 0) res = res * 2;
        }
        return res;
    }

    string decimalToBinary(int num, int size) {
        string res = "";
        while(num > 0) {
            int bit = num % 2;
            res += to_string(bit);
            num /= 2;
        }
        while(res.size() < size) {
            res += "0";
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0] == "0" ? "1" : "0";

        int vals = pow(2, n);
        unordered_map<int, int> dec;
        for(int i = 0; i < vals; i++) {
            dec[i] = 0;
        }

        for(auto& bin: nums) {
            int nm = binaryToDecimal(bin);
            if(!dec[nm]) dec[nm] = 1;
        }

        for(auto i : dec) {
            if(i.second == 0) {
                string ans = decimalToBinary(i.first, n);
                return ans;
            }
        }

        return "";
    }
};
