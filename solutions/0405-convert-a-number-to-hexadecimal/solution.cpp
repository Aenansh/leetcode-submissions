unordered_map<string, char> binToHex = {
    {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
    {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
    {"1000", '8'}, {"1001", '9'}, {"1010", 'a'}, {"1011", 'b'},
    {"1100", 'c'}, {"1101", 'd'}, {"1110", 'e'}, {"1111", 'f'}};

class Solution {
    void twosComplement(string& binary) {
        int n = binary.length();
        for (int i = 0; i < n; i++) {
            binary[i] = binary[i] == '1' ? '0' : '1';
        }
        if (binary[n - 1] == '0') {
            binary[n - 1] = '1';
            return;
        }
        char carry = '1';
        binary[n - 1] = '0';
        for (int i = n - 2; i >= 0; i--) {
            if (binary[i] == '1')
                binary[i] = '0';
            else {
                binary[i] = '1';
                break;
            }
        }
    }

public:
    string toHex(int num) {
        if(num == 0) return "0";
        long long nums = num;
        string binary(32, '0');
        bool neg = false;
        if (nums < 0) {
            neg = true;
            nums = abs(nums);
        }

        int idx = 31;
        while (nums > 0) {
            int bit = nums & 1;
            binary[idx] = '0' + bit;
            nums = nums >> 1;
            idx--;
        }
        if (neg)
            twosComplement(binary);

        string hexa;
        bool zeros = true;
        for (int i = 0; i <= 28; i += 4) {
            string bits;
            for (int j = 0; j <= 3; j++) {
                bits.push_back(binary[i + j]);
            }
            if (bits == "0000" && zeros)
                continue;
            zeros = false;
            hexa.push_back(binToHex[bits]);
        }
        return hexa;
    }
};
