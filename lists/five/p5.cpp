#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Present
{
	int h, w, d;
};

int compare(const void *a, const void * b)
{
	Present * pa = (Present *) a;
	Present * pb = (Present *) b;

	return (pb->d * pb->w) - (pa->d * pa->w);
}

int main()
{
	int presents;

	cin >> presents;

	Present arr[presents];

	for (int p = 0; p < presents; p++)
		cin >> arr[p].h >> arr[p].w >> arr[p].d;

	Present rot[3 * presents];

	int index = 0;
	for (int i = 0; i < presents; i++)
	{
		// Copy the original box
		rot[index].h = arr[i].h;
		rot[index].d = max(arr[i].d, arr[i].w);
		rot[index].w = min(arr[i].d, arr[i].w);
		index++;

		// First rotation of box
		rot[index].h = arr[i].w;
		rot[index].d = max(arr[i].h, arr[i].d);
		rot[index].w = min(arr[i].h, arr[i].d);
		index++;

		// Second rotation of box
		rot[index].h = arr[i].d;
		rot[index].d = max(arr[i].h, arr[i].w);
		rot[index].w = min(arr[i].h, arr[i].w);
		index++;
	}

	presents = 3 * presents;

	// qsort(rot, presents, sizeof(rot[0]), compare);

	int msh[presents];
	for (int i = 0; i < presents; i++ )
		msh[i] = rot[i].h;

	for (int i = 1; i < presents; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (rot[i].w < rot[j].w &&  rot[i].d < rot[j].d && msh[i] < msh[j] + rot[i].h)
				msh[i] = msh[j] + rot[i].h;
		}
	}

	int max = -1;
	for (int i = 0; i < presents; i++)
		if (max < msh[i])
			max = msh[i];

	cout << max << endl;

	return 0;
}