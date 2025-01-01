class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int pos1 = 0, pos2 = 0;
        for (auto i : position) {
            if (i % 2 == 0)
                pos2++;
            else
                pos1++;
        }
        if (pos1 < pos2)
            return pos1;
        else
            return pos2;
    }
};
