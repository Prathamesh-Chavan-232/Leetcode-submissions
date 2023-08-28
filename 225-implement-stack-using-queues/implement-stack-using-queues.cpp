class MyStack
{

    queue<int> q;

public:
    MyStack() {}

    void push(int x)
    {
        int count = q.size();
        q.push(x);
        while (count)
        {
            q.push(q.front());
            q.pop();
            count--;
        }
    }

    int pop()
    {
        int res = q.front();
        q.pop();
        return res;
    }

    int top()
    {
        int res = q.front();
        return res;
    }

    bool empty()
    {
        bool res = q.empty();
        return res;
    }
};