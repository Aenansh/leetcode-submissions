class Solution {
public:
    int minChanges(string s) {
        int minChange = 0;
        for(int i = 1; i < s.length(); i = i+2)
        {
            if(s[i - 1] != s[i])
            {
                minChange++;
            }
        }
        return minChange;
    }
};
