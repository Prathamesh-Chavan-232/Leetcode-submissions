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
       
    
        if(root == NULL) return root;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(q.size() > 1)
        {
            
            Node* n = q.front();
            q.pop();
            if(n == NULL)
            {
                q.push(NULL);
                continue;
            }
            n->next = q.front();
            if(n->left != NULL)
            {
                q.push(n->left);
            }
            if(n->right != NULL)
            {
                q.push(n->right);
            }
        }
        return root;
    }
};