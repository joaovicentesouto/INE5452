#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string line;

	while(getline(cin, line))
    {
        stack<bool> stack;
        string result = "correct";

        for (auto c : line)
        {
            if (c == '(')
                stack.push(true);
            else if (c == ')')
            {
                if (stack.empty())
                {
                    result = "incorrect";
                    break;
                }

                stack.pop();
            }
        }

        if (!stack.empty())
            result = "incorrect";

        cout << result << endl;
    }

	return 0;
}