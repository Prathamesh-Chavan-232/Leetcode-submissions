class Solution
{
    public:

        Node* connect(Node *root)
        {

            if (root == NULL) return root;

            queue<Node*> q;
            q.push(root);

            while (!q.empty())
            {
                int size = q.size();
                for (int i = 0; i < size; i++)
                {

                    Node *n = q.front();
                    q.pop();
                    
                    if(i == size - 1) n->next = NULL;
                    else n->next = q.front();
                    
                    if (n->left != NULL) q.push(n->left);

                    if (n->right != NULL) q.push(n->right);
                }
            }
            
            return root;
        }
};