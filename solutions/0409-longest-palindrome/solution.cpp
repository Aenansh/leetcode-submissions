class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        int oddLen = 0;
        int maxOdd = 0;
        int len = 0;
        for (auto f : freq) {
            if (f.second % 2 != 0) {
                maxOdd = max(maxOdd, f.second);
                oddLen += f.second - 1;
                
            } else if (f.second % 2 == 0) {
                len += f.second;
            }
        }
        if(maxOdd > 0) oddLen = oddLen + 1;
        return len + oddLen;
    }
};
