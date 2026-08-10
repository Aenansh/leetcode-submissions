class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count = 0;
        string rep = word;

        while (sequence.find(rep) != string::npos) {
            count++;
            rep += word;
        }

        return count;
    }
};
