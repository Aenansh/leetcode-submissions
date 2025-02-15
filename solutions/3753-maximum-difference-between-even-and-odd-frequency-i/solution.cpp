class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> count;
        for (auto i : s) {
            count[i]++;
        }
        int odd_max = INT_MIN, even_min = INT_MAX;

        for (auto i : count) {
            if (i.second % 2 == 0 && i.second < even_min)
                even_min = i.second;
            else if (i.second % 2 != 0 && i.second > odd_max)
                odd_max = i.second;
        }
        return odd_max - even_min;
    }
};
