class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size();
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        int matches = 0, i = 0, j = 0;
        while(i < n && j < m) {
            if(trainers[j] >= players[i]) {
                matches++;
                i++;
            }
            j++;
        }
        return matches;
    }
};
