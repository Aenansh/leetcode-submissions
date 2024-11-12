class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2 != 0) return false;
        stack<char> chk;
        for(char i : s)
        {
            if(i == '(' || i == '{' || i == '[')
            chk.push(i);
            else
            {
                if(chk.empty())
                return false;
                char c = chk.top(); 
                if((i == ')' && c != '(') || (i == ']' && c != '[') || (i == '}' && c != '{'))
                return false;
                else
                chk.pop();
            }
        }
        if(!chk.empty())
        return false;
        return true;
    }
};
