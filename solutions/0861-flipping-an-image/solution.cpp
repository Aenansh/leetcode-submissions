class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto& i : image){
            reverse(i.begin(), i.end());
            for(auto& j : i){
                if(j == 1) j = 0;
                else j = 1;
            }
        }
        return image;
    }
};
