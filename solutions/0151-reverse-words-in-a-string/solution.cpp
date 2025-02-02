class Solution {
public:
    string reverseWords(string s) {
        vector<string> rev;
        stringstream ss(s);
        string words;
        while(ss >> words){
            rev.push_back(words);
        }
        string word = "";
        for(int i = rev.size() - 1; i >= 0; i--){
            word += rev[i] + ' ';
        }
        word.erase(word.begin() + word.size() - 1);
        return word;
    }
};
