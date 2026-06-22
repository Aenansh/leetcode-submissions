class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();

        sort(begin(piles), end(piles));

        int coins = 0;
        int i = 0, j = n - 2;

        while (i < j) {
            coins += piles[j];
            i++;
            j -= 2;
        }

        return coins;
    }
};
