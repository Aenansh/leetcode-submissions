class Solution {
public:
    string stringHash(string s, int k) {
        string result = "";
        vector<int> val;
        for(int i = 0; i < s.length(); i = i + k)
        {
            string sub = s.substr(i, k);
            int sum = 0;
            for(int j = 0; j < sub.length(); j++)
            {
                sum += (sub[j] - 'a');
            }
            val.push_back(sum % 26);
        }
        for(auto i : val){
            result += 'a' + i;
        }
        return result;
    }
}; 
