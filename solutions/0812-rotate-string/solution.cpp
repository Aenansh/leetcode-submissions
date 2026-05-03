#define D 26
#define MOD 5381

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        int n = s.length();

        long long hash1 = 0;
        long long hash2 = 0;
        long long h = 1;

        for (int i = 0; i < n - 1; i++) {
            h = (h * D) % MOD;
        }

        for (int i = 0; i < n; i++) {
            hash1 = (hash1 * D + (s[i] - 'a')) % MOD;
            hash2 = (hash2 * D + (goal[i] - 'a')) % MOD;
        }

        for (int i = 0; i < n; i++) {
            if (hash1 == hash2) {
                bool isMatch = true;
                for (int j = 0; j < n; j++) {
                    if (s[(i + j) % n] != goal[j]) {
                        isMatch = false;
                        break;
                    }
                }
                if (isMatch)
                    return true;
            }
            int charToMove = s[i] - 'a';
            hash1 = (hash1 - (charToMove * h)) % MOD;
            if (hash1 < 0)
                hash1 += MOD;
            hash1 = (hash1 * D + charToMove) % MOD;
        }
        return false;
    }
};
