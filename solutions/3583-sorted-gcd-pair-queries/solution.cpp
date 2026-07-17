class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxVal = *max_element(begin(nums), end(nums));

        vector<int> divisorFreq(maxVal + 1, 0);
        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int j = 1; j * j <= num; j++) {
                if (num % j == 0) {
                    divisorFreq[j]++;
                    if (num / j != j)
                        divisorFreq[num / j]++;
                }
            }
        }

        vector<long long> pairsWithGcd(maxVal + 1, 0);
        for (int g = maxVal; g >= 1; g--) {
            long long count = divisorFreq[g];
            pairsWithGcd[g] = count * (count - 1) / 2;

            for (int mul = 2 * g; mul <= maxVal; mul += g) {
                pairsWithGcd[g] -= pairsWithGcd[mul];
            }
        }

        vector<long long> prefix(maxVal + 1, 0);

        for (int g = 1; g <= maxVal; g++) {
            prefix[g] = prefix[g - 1] + pairsWithGcd[g];
        }

        vector<int> res;

        for (long long q : queries) {
            int L = 1, R = maxVal;
            int temp = 1;

            while (L <= R) {
                int M = L + (R - L) / 2;

                if (prefix[M] > q) {
                    temp = M;
                    R = M - 1;
                } else
                    L = M + 1;
            }

            res.push_back(temp);
        }

        return res;
    }
};
