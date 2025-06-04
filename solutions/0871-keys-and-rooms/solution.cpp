class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto i : rooms[curr]) {
                if(!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        for(auto i : visited) {
            if(!i) return false;
        }
        return true;
    }
};
