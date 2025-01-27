class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long tsh = 0;
        for(auto i : shifts){
            tsh += i;
        }
        for(int i = 0; i < s.size(); i++){
            s[i] = 'a' + (s[i] - 'a' + tsh) % 26;
            tsh -= shifts[i];
        }
        return s;
    }
};
