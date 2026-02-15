class Solution {
public:
    string addBinary(string a, string b) {
        char carry = '0';
        string ans = "";
        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 && j >= 0) {
            char bit1 = a[i], bit2 = b[j];
            if (bit1 == bit2) {
                ans += carry;
                carry = bit1;
            } else {
                if (carry == '0')
                    ans += '1';
                else {
                    ans += '0';
                    carry = '1';
                }
            }
            i--, j--;
        }
        while(i >= 0) {
            if(a[i] == '1') {
                if(carry == '1') ans += '0';
                else ans += '1';
            } else {
                ans += carry;
                carry = '0';
            }
            i--;
        }
        while(j >= 0) {
            if(b[j] == '1') {
                if(carry == '1') ans += '0';
                else ans += '1';
            }
            else {
                ans += carry;
                carry = '0';
            }
            j--;
        }
        if(carry == '1') ans += carry;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
