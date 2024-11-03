class Solution {
public:
    bool rotateString(string s, string goal) {
        if((s.length() <= 1 && goal.length() <= 1) && (s != goal))
        return false;
        if(s.length() != goal.length())
        return false;
        for(int i = 0; i < s.length(); i++)
        {
            if(s == goal)
            return true;
            s = s.substr(1, s.length()) + s[0];
        }
        return false;
    }
};
