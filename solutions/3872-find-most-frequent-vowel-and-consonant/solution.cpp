class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> vowels;
        unordered_map<char, int> cons;

        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowels[c]++;
            else
                cons[c]++;
        }

        int maxV = 0, maxC = 0;
        for (auto [k, v] : vowels) {
            maxV = max(maxV, v);
        }
        for (auto [k, v] : cons) {
            maxC = max(maxC, v);
        }
        return maxV + maxC;
    }
};
