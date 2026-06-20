class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        int count = 0;
        string word;
        while (ss >> word)
            count++;

        return count;
    }
};
