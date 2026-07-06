class Solution {
    char getMirror(char c) { return (char)('a' + ('z' - c)); }

public:
    long long calculateScore(string s) {
        long long n = s.length();
        unordered_map<char, stack<long long>> mp;

        long long score = 0;
        for (long long i = 0; i < n; i++) {
            char ch = s[i];
            char mi = getMirror(ch);

            if (mp.find(mi) != mp.end() && mp[mi].top() < i) {
                score += (i - mp[mi].top());
                mp[mi].pop();
                if (mp[mi].empty())
                    mp.erase(mi);
            } else {
                mp[ch].push(i);
            }
        }

        return score;
    }
};
