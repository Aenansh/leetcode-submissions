class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        vector<int> ones;
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 1)
                ones.push_back(i);
        }

        if (ones.empty()) {
            n = n - (m - m / 2);
        } else {
            if (ones[0] != 0) {
                int empty = ones[0] - 1;
                n = n - (empty - empty / 2);
            }

            int len = ones.size();
            if (ones[len - 1] != m - 1) {
                int empty = m - ones[len - 1] - 2;
                n = n - (empty - empty / 2);
            }

            for (int i = 1; i < len; i++) {
                int d = ones[i] - ones[i - 1] - 3;
                if (d <= 0)
                    continue;

                n = n - (d - d / 2);
            }
        }

        return n <= 0;
    }
};
