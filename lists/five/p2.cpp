#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

enum Color
{
    UNCOLOR = 0,
    RED     = 1,
    ORANGE  = 2,
    GREEN   = 3,
    BLUE    = 4
};

struct Cilinder
{
	int h, r;
    int base;
    Color color;
};

int compare(const void *a, const void * b)
{
	Cilinder * pa = (Cilinder *) a;
	Cilinder * pb = (Cilinder *) b;

	return pb->base - pa->base;
}

bool stack_rules(vector<Color> stack, Color c)
{
    if (c == Color::RED && stack.back() == Color::ORANGE)
        return false;

    if (c == Color::ORANGE && stack.back() == Color::BLUE)
        return false;

    if (c == Color::BLUE && stack.back() == Color::GREEN)
        return false;

    if (c == Color::GREEN && stack.back() == Color::RED)
        return false;
    
    return true;
}

int main()
{
	int cilinders;

    while (cin >> cilinders)
    {
        if (!cilinders)
            break;

        Cilinder rot[cilinders];

        for (int p = 0; p < cilinders; p++)
        {
            string s;

            cin >> rot[p].h >> rot[p].r;
            rot[p].base = M_PI * pow(rot[p].r, 2);

            cin >> s;

            if (s == "VERMELHO")
                rot[p].color = Color::RED;
            else if (s == "LARANJA")
                rot[p].color = Color::ORANGE;
            else if (s == "VERDE")
                rot[p].color = Color::GREEN;
            else if (s == "AZUL")
                rot[p].color = Color::BLUE;
        }

        qsort(rot, cilinders, sizeof(rot[0]), compare);

        int stacks_size[cilinders];
        vector<vector<Color>> stacks_colors(cilinders);

        for (int i = 0; i < cilinders; i++ )
        {
            stacks_size[i] = rot[i].h;
            stacks_colors[i].push_back(rot[i].color);
        }

        for (int i = 1; i < cilinders; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (rot[i].base < rot[j].base
                    && stacks_size[i] < stacks_size[j] + rot[i].h
                    && stack_rules(stacks_colors[j], rot[i].color)
                )
                    stacks_size[i] = stacks_size[j] + rot[i].h;
            }
        }

        int max = -1;
        for (int i = 0; i < cilinders; i++)
            if (max < stacks_size[i])
                max = stacks_size[i];

        cout << max << " centimetro(s)" << endl;
    }

	return 0;
}