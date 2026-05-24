/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<Node*> q1;
        queue<Node*> q2;

        q1.push(root);

        while (!q1.empty()) {
            Node* temp = q1.front();
            q1.pop();

            if (temp->left)
                q2.push(temp->left);
            if (temp->right)
                q2.push(temp->right);

            if (!q1.empty()) {
                temp->next = q1.front();
            } else {
                temp->next = nullptr;
                while (!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop();
                }
            }
        }
        return root;
    }
};
