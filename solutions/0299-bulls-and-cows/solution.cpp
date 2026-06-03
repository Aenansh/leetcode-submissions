class Solution {
public:
    string getHint(string secret, string guess) {
        int n = guess.size();

        int bulls = 0, cows = 0;

        unordered_map<char, int> smp;
        unordered_map<char, int> gmp;

        for (int i = 0; i < n; i++) {
            smp[secret[i]]++;
            gmp[guess[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (guess[i] == secret[i]) {
                bulls++;
                smp[secret[i]]--;
                if (smp[secret[i]] == 0)
                    smp.erase(secret[i]);
                gmp[guess[i]]--;
                if (gmp[guess[i]] == 0)
                    gmp.erase(guess[i]);
            }
        }

        for(auto& [k, v] : gmp) {
            if(smp[k]) {
                cows += min(v, smp[k]);
            }
        }

        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';

        return ans;
    }
};
