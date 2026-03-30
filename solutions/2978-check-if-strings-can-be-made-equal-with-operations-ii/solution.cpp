class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();

        unordered_map<char, int> even1;
        unordered_map<char, int> even2;

        for (int i = 0; i < n; i += 2) {
            even1[s1[i]]++;
            even2[s2[i]]++;
        }
        for (auto& i : even1) {
            if (!even2[i.first])
                return false;
            if (even2[i.first] != i.second)
                return false;
        }
        unordered_map<char, int> odd1;
        unordered_map<char, int> odd2;
        for (int i = 1; i < n; i += 2) {
            odd1[s1[i]]++;
            odd2[s2[i]]++;
        }
        for (auto& i : odd1) {
            if (!odd2[i.first])
                return false;
            if (odd2[i.first] != i.second)
                return false;
        }
        return true;
    }
};
