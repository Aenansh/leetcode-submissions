class Solution {
public:
    string clearDigits(string s) {
        stack<char> s1;
        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else{
                s1.push(s[i]);
            }
        }
        string ans;
        while(!s1.empty()){
            ans += s1.top();
            s1.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
