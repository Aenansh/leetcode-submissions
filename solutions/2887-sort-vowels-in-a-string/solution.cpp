class Solution {
public:
    string sortVowels(string s) {
        string vowels = "";
        for(char c: s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u' || c =='A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                vowels += c;
            }
        }
        sort(vowels.begin(), vowels.end(), greater<int>());
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] =='u' || s[i] =='A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                s[i] = vowels.back();
                vowels.pop_back();
            }
        }
        return s;
    }
};
