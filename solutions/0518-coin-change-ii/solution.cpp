class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long int> table(amount + 1, 0);
        table[0] = 1;

        for(auto c : coins) {
            for(int i = c; i <= amount; i++) {
                table[i] += table[i - c];
            }
        }
        return table[amount];
    }
};
