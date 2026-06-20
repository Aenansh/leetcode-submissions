class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> have;
        unordered_map<char, int> need = {
            {'b', 1}, {'a', 1}, {'l', 2}, {'o', 2}, {'n', 1}};

        int count = INT_MAX;

        for (char c : text) {
            if (need.find(c) != need.end())
                have[c]++;
        }

        if (have.size() != need.size())
            return 0;

        for (auto& [ch, cnt] : have) {
            count = min(count, cnt / need[ch]);
        }

        return count;
    }
};
