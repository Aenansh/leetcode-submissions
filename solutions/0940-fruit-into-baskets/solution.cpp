class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxfruits = 0;
        unordered_map<int, int> uniqueFruits;
        int left = 0;
        for(int i = 0; i < fruits.size(); i++) {
            uniqueFruits[fruits[i]]++;
            while(uniqueFruits.size() > 2) {
                uniqueFruits[fruits[left]]--;
                if(uniqueFruits[fruits[left]] == 0) uniqueFruits.erase(fruits[left]);
                left++;
            }
            maxfruits = max(maxfruits, i - left + 1);
        }
        return maxfruits;
    }
};
