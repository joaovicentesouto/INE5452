#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <string>

using namespace std;

static long int possibilities;

struct Bishop
{
    Bishop(int x0, int y0) : x(x0), y(y0)
    {
    }

    ~Bishop() = default;

    int x, y;
};

bool playable(const vector<Bishop> & bishops, const Bishop& b)
{
    for (const auto & e : bishops)
        if (abs(e.x - b.x) == abs(e.y - b.y))
            return false;

    return true;
}

void positioning(
    vector<bool> & board,
    unordered_map<vector<bool>, bool> & history,
    vector<Bishop> & bishops,
    int remaning
)
{
    if (!remaning)
    {
        if (!history[board])
        {
            possibilities++;
            cout << possibilities << endl;
            history[board] = true;
        }

        return;
    }

    int n = sqrt(board.size());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i * n + j])
                continue;
            
            Bishop b(i, j);
            
            if (!playable(bishops, b))
                continue;
            
            board[i * n + j] = true;
            bishops.push_back(b);

            positioning(board, history, bishops, remaning - 1);

            bishops.pop_back();
            board[i * n + j] = false;
        }
    }
}

int main(void)
{
    int n = 0, k = 0;

    while (cin >> n >> k)
    {
        if (!n || !k)
            break;
        
        vector<Bishop> bishops;
        vector<bool> board(n * n, false);
        unordered_map<vector<bool>, bool> history;
        possibilities = 0;

        positioning(board, history, bishops, k);

        cout << possibilities << endl;
    }
}