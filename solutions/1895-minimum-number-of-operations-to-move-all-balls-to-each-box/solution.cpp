class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.length(), 0);
        for(int i = 0; i < boxes.length(); i++){
            for(int j = 0; j < boxes.length(); j++){
                if(i != j && boxes[j] == '1'){
                    ans[i] += abs(i - j);
                }
            }
        }
        return ans;
    }
};
