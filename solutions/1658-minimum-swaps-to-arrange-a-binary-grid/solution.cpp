class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing_zeros(n, 0);
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    zeros++;
                } else {
                    break;
                }
            }
            trailing_zeros[i] = zeros;
        }
        int moves = 0;
        for (int i = 0; i < n; i++) {
            int required_zeros = n - 1 - i;
            if (trailing_zeros[i] >= required_zeros) {
                continue;
            }
            int j = i + 1;
            while (j < n && trailing_zeros[j] < required_zeros) {
                j++;
            }
            if (j == n) {
                return -1;
            }
            while (j > i) {
                swap(trailing_zeros[j], trailing_zeros[j - 1]);
                j--;
                moves++;
            }
        }

        return moves;
    }
};
