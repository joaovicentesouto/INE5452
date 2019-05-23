#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	while (true)
	{
		uint64_t a, b, c;

		cin >> a >> b;

		if (!a && !b)
			break;

		c = a ^ b;

		size_t count = 0;
		for (size_t i = 0; i < 64; ++i)
		{
			count += (c & 0x1);

			c = c >> 1;
		}

		cout << count << endl;
	}

	return 0;
}
