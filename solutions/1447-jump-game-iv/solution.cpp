class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> common;

        for (int i = 0; i < n; i++) {
            common[arr[i]].push_back(i);
        }

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        int jumps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                if (curr == (n - 1))
                    return jumps;

                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                for (auto idx : common[arr[curr]]) {
                    if (!visited[idx]) {
                        visited[idx] = true;
                        q.push(idx);
                    }
                }
                common.erase(arr[curr]);
            }
            jumps++;
        }
        return -1;
    }
};
