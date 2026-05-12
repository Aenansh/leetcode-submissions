class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [](auto a, auto b) { return a[1] - a[0] > b[1] - b[0]; });

        int ans = 0;
        int curr_energy = 0;
        for (auto task : tasks) {
            int ac_en = task[0];
            int min_en = task[1];
            if (curr_energy < min_en) {
                ans += min_en - curr_energy;
                curr_energy = min_en;
            }
            curr_energy -= ac_en;
        }
        return ans;
    }
};
