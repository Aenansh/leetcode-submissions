class Solution {
public:
    long long calculateScore(vector<string>& instructions,
                             vector<int>& values) {
        int n = instructions.size();

        long long sum = 0;
        vector<bool> visited(n, false);

        int i = 0;

        while (i >= 0 && i < n) {
            if (visited[i]) {
                break;
            }
            visited[i] = true;
            if (instructions[i] == "add") {
                sum += values[i];
                i++;
            } else {
                i += values[i];
            }
        }

        return sum;
    }
};
