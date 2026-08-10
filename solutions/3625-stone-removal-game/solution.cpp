class Solution {
public:
    bool canAliceWin(int n) {
        int player = 0, remove = 10;

        while(n >= remove) {
            n -= remove;
            remove--;
            player = !player;
        }

        return player;
    }
};
