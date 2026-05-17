class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0) return true;
        int n = arr.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(start);
        visited[start] = true;

        int d[2] = {1, -1};
        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int i = 0; i < 2; i++) {
                int idx = curr + (d[i] * arr[curr]);
                if(idx >= 0 && idx < n && !visited[idx]) {
                    if(arr[idx] == 0) return true;
                    q.push(idx);
                    visited[idx] = true;
                }
            }
        }
        return false;
    }
};
