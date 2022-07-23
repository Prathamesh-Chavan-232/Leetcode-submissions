struct Node
{
    int data;	// Value of node
    struct Node *left, *right;	// left and right pointers
    int lc;	// this variable keeps a count of number of elements present in left subtree of this Node

   	// Constructor for the Node
    Node(int data)
    {

       	// Initialising all the member variables whenever a node is to be created.
        this->data = data;
        left = right = NULL;
        lc = 0;
    }
};

class Solution
{
    public:

        int insert(struct Node *node, int key)
        {
            struct Node *r = NULL, *p;	// pointer p is used for creating the new node when its insertion position is found.
            int c = 0;	// keeps the count of elements lesser than "key"

           	// this while loop tends to find the position at which "key" is inserted.

            while (node != NULL)
            {
                r = node;
                if ((node->data) >= key)
                {
                   	// Carefully note this line of code, if the element to be inserted (key) is lesser than or equal to the 
                   	// current node, then the count of "lc" variable (which represents no. of elements to left of current node)
                   	// is incremented by 1.
                    node->lc = (node->lc) + 1;

                   	// Since the key is smaller than current node, so we will look for its position in left subtree.
                    node = node->left;
                }
                else
                {
                   	//  In case the key is bigger than the current node, it means that key is also bigger than all the
                   	// nodes present in left subtree of current node. And here we will be making using of lc variable.
                    c += 1 + (node->lc);

                   	// Since the key is greater than current node, so we will look for its position in right subtree.
                    node = node->right;
                }
            }

           	// This piece of code just inserts the key to its position, nothing special.
            p = new Node(key);
            if (p->data <= r->data)
                r->left = p;
            else
                r->right = p;

           	// Finally all the elements lesser than the key is returned.
            return c;
        }
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> vect(n, 0);	// vector which stores the answer

        int j = 1;

       	// This while loop just checks if the input array is in non-decreasing fashion. We don't
       	// need to build BST in this case. Thus saving time. 
       	// If array is in non-decreasing fashion,  we will return a vector of 0's
       	// because in this case, no element in the right of the current element will the greater than it.
        while (j < n && nums[j - 1] <= nums[j]) j++;
        if (j == n) return vect;

        j = n - 2;

       	// Similarly we also check if input array is in non-increasing fashion, in this case too we dont need BST
       	// If this is the case, then appropriate values is stored in "vect" array.
        while (j > -1 && nums[j] >= nums[j + 1])
        {
            if (nums[j] > nums[j + 1])
                vect[j] = n - j - 1;
            if (nums[j] == nums[j + 1]) vect[j] = vect[j + 1];
            j--;
        }
       	// if array is in non-increasing fashion, then return "vect".
        if (j == -1) return vect;

       	//  If input array is just random, then the last element is made as root of BST.
        struct Node *root = new Node(nums[n - 1]);

       	// We will keep inserting elements into BST from the end of the input array.
       	// And as discussed above, "insert" function will return the count of elements lesser 
       	// than the current variable.
        for (int i = n - 2; i > -1; i--)
            vect[i] = insert(root, nums[i]);

       	// Answer returned.
        return vect;
    }
};