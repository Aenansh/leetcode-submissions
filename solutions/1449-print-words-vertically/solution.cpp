class Solution {
public:
    int biggestWord(string s) {
        stringstream ss(s);
        string word;
        int maxlen = 0;
        while (ss >> word) {
            maxlen = max(maxlen, static_cast<int>(word.length()));
        }
        return maxlen;
    }
    vector<string> printVertically(string s) {
        int n = biggestWord(s);
        stringstream ss(s);
        string word;
        vector<vector<char>> graph;

        while (ss >> word) {
            vector<char> c(n, ' ');
            for (int k = 0; k < word.size(); k++) {
                c[k] = word[k];
            }
            graph.push_back(c);
        }
        vector<string> ans;

        for(int i = 0; i < n; i++){
            string k = "";
            for(int j = 0; j < graph.size(); j++){
                k += graph[j][i];
            }
            int w = k.size() - 1;
            while(k[w] == ' '){
                k.erase(k.begin() + w);
                w = k.size() - 1;
            }
            ans.push_back(k);
        }
        return ans;
    }
};
