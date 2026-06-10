class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> scores(n, 0);

        for(int i = 0; i < n; i++) {
            scores[edges[i]] += i;
        }

        long long maxScore = 0;
        int ansNode = -1;
        for(int i = 0; i < n; i++) {
            if(scores[i] > maxScore) {
                maxScore = scores[i];
                ansNode = i;
            }
        }
        return ansNode;
    }
};
