#include <iostream>
#include <vector>

using namespace std;

class BinaryTree
{
public:
    BinaryTree()
    {

    }

    ~BinaryTree()
    {
        delete _root;
    }

    void insert(int v)
    {
        if (_root)
            _root->insert(v);
        else
            _root = new Node(v);
    }

    void pre_order()
    {
        if (_root)
            _root->pre_order();
    }
    
    void in_order()
    {
        if (_root)
            _root->in_order();
    }

    void pos_order()
    {
        if (_root)
            _root->pos_order();
    }

private:
    struct Node
    {
        Node(int v) :
            _value(v)
        {

        }

        ~Node()
        {
            delete _left;
            delete _right;
        }

        void insert(int v)
        {
            if (v < _value)
            {
                if (_left)
                    _left->insert(v);
                else
                    _left = new Node(v);
            }
            else
            {
                if (_right)
                    _right->insert(v);
                else
                    _right = new Node(v);
            }
        }

        void pre_order()
        {
            cout << " " << _value;

            if (_left)
                _left->pre_order();
            
            if (_right)
                _right->pre_order();
        }
        
        void in_order()
        {
            if (_left)
                _left->in_order();

            cout << " " << _value;
            
            if (_right)
                _right->in_order();
        }

        void pos_order()
        {
            if (_left)
                _left->pos_order();

            if (_right)
                _right->pos_order();
            
            cout << " " << _value;
        }

        Node *_left{nullptr}, *_right{nullptr};
        int _value;
    };

    Node * _root{nullptr};
};

using namespace std;

int main()
{
    int n;
    
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int m;
        BinaryTree tree;

        cin >> m;
        for (int j = 0; j < m; ++j)
        {
            int aux;

            cin >> aux;
            tree.insert(aux);
        }

        cout << "Case " << i+1 << ":" << endl;

        cout << "Pre.:";
        tree.pre_order();
        cout << endl;

        cout << "In..:";;
        tree.in_order();
        cout << endl;

        cout << "Post:";;
        tree.pos_order();
        cout << endl;
        cout << endl;
    }


	return 0;
}