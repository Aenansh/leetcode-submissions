class Solution {
    struct Node {
        Node* links[26];
        int idx;
        Node(int idx) {
            this->idx = idx;
            for (int i = 0; i < 26; i++)
                links[i] = nullptr;
        }
        ~Node() {
            for(int i = 0; i < 26; i++) {
                delete links[i];
            }
        }
    };
    void insert(Node* root, int i, vector<string>& wordsContainer) {
        string word = wordsContainer[i];
        int n = word.length();

        for (int j = n - 1; j >= 0; j--) {
            char c = word[j];
            int c_idx = c - 'a';

            if (root->links[c_idx] == nullptr) {
                root->links[c_idx] = new Node(i);
            }
            root = root->links[c_idx];
            if (wordsContainer[root->idx].length() > n)
                root->idx = i;
        }
    }

    int search(Node* root, string& word) {
        int res = root->idx;
        int n = word.length();

        for (int j = n - 1; j >= 0; j--) {
            int c_idx = word[j] - 'a';
            root = root->links[c_idx];

            if (root == nullptr)
                return res;
            res = root->idx;
        }
        return res;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();

        vector<int> results(n);

        Node* trie = new Node(0);

        for (int i = 0; i < m; i++) {
            int idx = trie->idx;
            if (wordsContainer[idx].length() > wordsContainer[i].length())
                trie->idx = i;
            insert(trie, i, wordsContainer);
        }

        for (int i = 0; i < n; i++) {
            results[i] = search(trie, wordsQuery[i]);
        }

        delete trie;
        return results;
    }
};
