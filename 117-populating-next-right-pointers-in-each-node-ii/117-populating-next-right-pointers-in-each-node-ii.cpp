/*
    Link - https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
    Problem - Populating the next right pointer
    Difficulty - Medium (binary trees - BFS)
    contest - no
    Status - Solved
    Date - 14/5/22
*/
/*  Approach -

    Solution 1 -
        At the start we Push Root & a NULL to the queue (since root->next will be NULL)

        while(q.size() > 1) we keep this condn to avoid infinitely pushing null to the queue
        {
            bfs algorithm
            for every node->next = q.front();
            if (node == NULL) push a NULL to the queue;
        }

    Why this works -
        In bfs, Every node will push its children to the queue, so 1 will push -> 2,3
        Now after 1 there is a NULL, NULL will push a NULL above 3 (exactly at the end of every level)

        Therefore if we push a NULL at the end of the 1st level, it will be pushed to the end of the every level

    Solution 2 -
        
        Use BFS Traversal to access each level of the tree
        Keep track of when the level ends, As last element in the lvl will point to null

*/

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution1
{
public:
    Node *connect(Node *root)
    {

        if (root == NULL)
            return root;

        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (q.size() > 1)
        {

            Node *n = q.front();
            q.pop();
            if (n == NULL)
            {
                q.push(NULL);
                continue;
            }
            n->next = q.front();
            if (n->left != NULL)
            {
                q.push(n->left);
            }
            if (n->right != NULL)
            {
                q.push(n->right);
            }
        }
        return root;
    }
};

class Solution2
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
