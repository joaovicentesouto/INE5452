#include <iostream>
#include <stack>
#include <queue>

using namespace std;

enum Type
{
    Stack         = 1,
    Queue         = 2,
    PriorityQueue = 3,
};

int main()
{
    int n;

    while (cin >> n)
    {
        stack<int> stack;
        queue<int> queue;
        priority_queue<int> pqueue;
        int type = 0;

        //! Not sure
        type |= 1 << Type::Stack;
        type |= 1 << Type::Queue;
        type |= 1 << Type::PriorityQueue;

        for (auto i = 0; i < n; ++i)
        {
            int op, value;
            cin >> op >> value;

            if (op == 1) //! push
            {
                if (type & 1 << Type::Stack)
                    stack.push(value);
                
                if (type & 1 << Type::Queue)
                    queue.push(value);
                
                if (type & 1 << Type::PriorityQueue)
                    pqueue.push(value);
            }
            else //! pop
            {
                if (type & 1 << Type::Stack)
                {
                    if (stack.top() == value)
                        stack.pop();
                    else
                        type &= ~(1 << Type::Stack);
                }
                
                if (type & 1 << Type::Queue)
                {
                    if (queue.front() == value)
                        queue.pop();
                    else
                        type &= ~(1 << Type::Queue);
                }
                
                if (type & 1 << Type::PriorityQueue)
                {
                    if (pqueue.top() == value)
                        pqueue.pop();
                    else
                        type &= ~(1 << Type::PriorityQueue);
                }
            }
        }

        switch (type)
        {
            case 1 << Type::Stack:
                cout << "stack" << endl;
                break;
            
            case 1 << Type::Queue:
                cout << "queue" << endl;
                break;
            
            case 1 << Type::PriorityQueue:
                cout << "priority queue" << endl;
                break;
        
            default:
                if (type)
                    cout << "not sure" << endl;
                else
                    cout << "impossible" << endl;
                break;
        }
    }

	return 0;
}