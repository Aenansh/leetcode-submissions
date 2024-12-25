class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length() < 26) return false;
        unordered_map<char, int> alpha;
        for(int i = 0; i < 26; i++){
            alpha['a' + i] = 0;
        }
        for(char c : sentence){
            if(alpha[c] == 0){
                alpha[c]++;
            }
        }
        for(auto i : alpha){
            if(i.second == 0) return false;
        }
        return true;
    }
};
