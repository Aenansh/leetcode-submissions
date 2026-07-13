class Solution {
    int countDigits(int n) {
        int count = 0;
        while (n != 0) {
            n = n / 10;
            count++;
        }
        return count;
    }

public:
    vector<int> sequentialDigits(int low, int high) {
        int L = countDigits(low);
        int R = countDigits(high);

        string num = "123456789";

        vector<int> res;

        for (int S = L; S <= R; S++) {
            for (int j = 0; j <= 9 - S; j++) {
                int n = stoi(num.substr(j, S));
                if (n <= high && n >= low)
                    res.push_back(n);
                else
                    continue;
            }
        }
        return res;
    }
};
