class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int L = 0, R = 0;
        for(int i = 0; i < n; i++) {
            if(moves[i] == 'L') L++;
            else if(moves[i] == 'R') R++;
        }

        int dist = n - (L + R);
        dist += L > R ? L - R : R - L;
        return dist;
    }
};
