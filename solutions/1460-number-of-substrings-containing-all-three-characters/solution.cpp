class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int L = 0, count = 0;
        int n = s.length();

        for (int R = 0; R < n; R++) {
            char c = s[R];
            mp[c]++;

            while (mp.size() == 3) {
                char l = s[L];
                count = count + 1 + (n - 1 - R);
                mp[l]--;
                if (mp[l] == 0)
                    mp.erase(l);
                L++;
            }
        }

        return count;
    }
};
