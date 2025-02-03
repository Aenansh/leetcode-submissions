class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> rev;
        string word;
        while(ss >> word){
            reverse(word.begin(), word.end());
            rev.push_back(word);
        } 
        string ans = "";
        for(auto i : rev){
            ans += i + ' ';
        }
        ans.erase(ans.begin() + ans.size() - 1);
        return ans;
    }
};
